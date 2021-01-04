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
buffer fifolist;
void init(buffer* head)
{
	head->next = head;
	head->prev = head;
}


void insert(buffer* head, int data_num)
{
	buffer* p = &cache_buffer[(i % 8192)];
	i++;
	p->blkno = data_num;
	p->next = head->next;
	p->prev = head->next->prev;
	head->next->prev = p;
	head->next = p;
	
}
int isfull()
{
	if (i > 8191)
		return 1;
	else
		return 0;
}

void delete()
{
	buffer* p = &cache_buffer[(i % 8192)];
	p->next->prev = p->prev;
	p->prev->next = p->next;
}

int search(buffer* head,int data_num)
{
	buffer* p = head->next;
	for (; p != head; p = p->next)
	{
		if (p->blkno == data_num)
			return 1;
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

	buffer* head = &fifolist;
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
				delete();
				insert(head, blkno);
			}
			else
			{
				insert(head, blkno);
			}
		}
		fd = (fscanf(fp, "%d", &blkno));
	}
	hitratio = (double)hit*100/total;
	printf("hit ratio = %.10lf %%", hitratio);

	fclose(fp);

	return 0;
}

