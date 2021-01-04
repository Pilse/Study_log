#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	MAX_CACHE_SIZE		8192

#define HASH_SIZE           6151
#define TRACE_FILE_NAME		"ref_stream.txt"



struct buffer {
    unsigned long blkno;
    struct buffer* next, * prev;
    struct buffer* hash_next, * hash_prev;
};


struct buffer cache_buffer[MAX_CACHE_SIZE];
struct buffer hash_table[HASH_SIZE];


#if 1
struct buffer lrulist;
#else
struct buffer fifolist;
#endif

unsigned long curtime = 0, hit = 0, miss = 0;


void hash_init()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash_table[i].hash_next = &hash_table[i];
        hash_table[i].hash_prev = &hash_table[i];
    }
}

unsigned long hash_function(unsigned long key)
{
    return key % HASH_SIZE;
}
struct buffer* hash_search(unsigned long blkno)
{
    int i = 0;
    unsigned long hash_value = hash_function(blkno);
    struct buffer* dp = &hash_table[hash_value];
    struct buffer* bp;
    for (bp = dp->hash_next; bp != dp; bp = bp->hash_next)
    {
        if (bp->blkno == blkno)
        {
            return bp;
        }
    }
    return NULL;
}

void hash_delete(struct buffer* bp)
{
    bp->hash_next->hash_prev = bp->hash_prev;
    bp->hash_prev->hash_next = bp->hash_next;
    bp->hash_next = bp->hash_prev = bp;

}

void hash_add(struct buffer* bp)
{
    unsigned long hash_value = hash_function(bp->blkno);
    struct buffer* dp = &hash_table[hash_value];
    bp->hash_next = dp->hash_next;
    bp->hash_prev = dp;
    dp->hash_next->hash_prev = bp;
    dp->hash_next = bp;
}

//--------------------lru-----------------------

void lruin(struct buffer* bp)
{
    struct buffer* dp = &lrulist;

    bp->next = dp->next;
    bp->prev = dp;
    (dp->next)->prev = bp;
    dp->next = bp;

}

struct buffer* lruout()
{
    struct buffer* bp;
    bp = lrulist.prev;
    (bp->prev)->next = bp->next;
    (bp->next)->prev = bp->prev;


    return bp;

}

void reorder(struct buffer* bp)
{
    (bp->prev)->next = bp->next;
    (bp->next)->prev = bp->prev;
    lruin(bp);
}

void init()
{
    int i;
    lrulist.next = lrulist.prev = &lrulist;
    for (i = 0; i < MAX_CACHE_SIZE; i++)
    {
        cache_buffer[i].blkno = 0;
        cache_buffer[i].next = cache_buffer[i].prev = NULL;

        lruin(&cache_buffer[i]);
        hash_add(&cache_buffer[i]);
    }

}

void pgref(unsigned long blkno)
{
    struct buffer* bufp;
    bufp = hash_search(blkno);
    if (bufp)
    {
        hit++;
        reorder(bufp);

    }
    else
    {
        miss++;
        bufp = lruout();
        hash_delete(bufp);
        bufp->blkno = blkno;
        lruin(bufp);
        hash_add(bufp);

    }
}

int main(int argc, char* argv[])
{
    int	ret;
    unsigned long blkno;
    FILE* fp = NULL;
    double start, stop;

    hash_init();
    init();

    if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL) {
        printf("%s trace file open fail.\n", TRACE_FILE_NAME);

        return 0;
    }
    else {
        printf("start simulation!\n");
    }
    start = clock();
    while (ret = fscanf(fp, "%lu", &blkno) != EOF)
    {
        curtime++;
        pgref(blkno);
    }
    stop = clock();
    fclose(fp);

    printf("hit ratio = %f, miss ratio= %f time = %lf \n", (float)hit / (float)curtime, (float)miss / (float)curtime, (stop - start) / CLOCKS_PER_SEC);
   
    return 0;
}

