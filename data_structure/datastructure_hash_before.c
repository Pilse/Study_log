#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>

#define	MAX_CACHE_SIZE		8192


#define TRACE_FILE_NAME		"ref_stream.txt"



struct buffer {
    unsigned long blkno;
    struct buffer* next, * prev;
};


struct buffer cache_buffer[MAX_CACHE_SIZE];


#if 1
struct buffer lrulist;
#else
struct buffer fifolist;
#endif

unsigned long curtime, hit, miss;

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
        cache_buffer[i].blkno = ~0;
        cache_buffer[i].next = cache_buffer[i].prev = NULL;

        lruin(&cache_buffer[i]);
    }

}
struct buffer* findblk(unsigned long blkno)
{
    struct buffer* dp, * bp;
    dp = &lrulist;
    for (bp = dp->next; bp != dp; bp = bp->next)
    {
        if (bp->blkno == blkno)
            return bp;

    }
    return NULL;

}

void pgref(unsigned long blkno)
{
    struct buffer* bufp;

    bufp = findblk(blkno);
    if (bufp)
    {
        hit++;

        reorder(bufp);

    }
    else
    {
        miss++;

        bufp = lruout();
        bufp->blkno = blkno;
        lruin(bufp);

    }
}

int main(int argc, char* argv[])
{
    int	ret;
    unsigned long blkno;
    double start,stop;
    FILE* fp = NULL;

    init();

    if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL) {
        printf("%s trace file open fail.\n", TRACE_FILE_NAME);

        return 0;
    }
    else {
        printf("start simulation!\n");
    }
    start =clock();
    while (ret = fscanf(fp, "%lu", &blkno) != EOF)
    {
        curtime++;
        pgref(blkno);
    }
    stop=clock();
    
    fclose(fp);

    printf("hit ratio = %f, miss ratio= %f time = %lf \n", (float)hit / (float)curtime, (float)miss / (float)curtime, (stop - start) / CLOCKS_PER_SEC);

    return 0;
}

