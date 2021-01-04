#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define	MAX_CACHE_SIZE		8192

// 데이터 참조 스트림이 저장된 파일 
#define TRACE_FILE_NAME		"ref_stream.txt"


typedef struct buffer {
	unsigned long blkno;
	struct buffer* next, * prev;
}buffer;

buffer cache_buffer[MAX_CACHE_SIZE];
int i = 0;

//헤드 노드 선언
buffer lrulist;
void init(buffer* head)
{
	head->next = head;
	head->prev = head;
}

buffer* node=NULL;
void insert(buffer* head, int data_num)
{
	buffer* p = NULL;
	if (node != NULL)
		p = node;
	else
		p = &cache_buffer[i++];
	p->blkno = data_num;
	p->next = head->next;
	p->prev = head->next->prev;
	head->next->prev = p;
	head->next = p;
}

void lru_insert(buffer* head,buffer* node)
{
	node->next = head->next;
	node->prev = head->next->prev;
	head->next->prev = node;
	head->next = node;


}
int isfull()
{
	if (i > 8191)
		return 1;
	else
		return 0;
}

void delete(buffer* head)
{
	buffer* p = head->prev;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	node = p;
}

void lru_delete(buffer* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = node;
	node->prev = node;
}

int search(buffer* head, int data_num)
{
	buffer* p = head->next;
	for (; p != head; p = p->next)
	{
		if (p->blkno == data_num)
		{
			lru_delete(p);
			lru_insert(head,p);
			return 1;
		}
	}
	return 0;


}

int main(int argc, char* argv[])
{
	unsigned long blkno = 0;
	unsigned long hit = 0;
	unsigned long total = 0;
	double hitratio = 0;
	FILE* fp = NULL;

	buffer* head = &lrulist;
	init(head);

	if ((fp = fopen(TRACE_FILE_NAME, "r")) == NULL)
	{
		printf("%s trace file open fail.\n", TRACE_FILE_NAME);

		return 0;
	}
	else
	{
		printf("start simulation!\n");
	}

	int fd = (fscanf(fp, "%d", &blkno));
	while (fd != EOF)
	{
		total++;
		if (search(head, blkno))
		{
			hit++;
		}
		else
		{
			if (isfull())
			{
				delete(head);
				insert(head, blkno);
			}
			else
			{
				insert(head, blkno);
			}
		}
		fd = (fscanf(fp, "%d", &blkno));
	}
	hitratio = (double)hit * 100 / total;
	printf("hit ratio = %.10lf %%", hitratio);

	fclose(fp);

	return 0;
}