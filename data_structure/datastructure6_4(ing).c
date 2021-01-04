#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LIST 46

typedef struct linkedlist
{
	int lots;
	struct linkedlist* next;
	struct linkedlist* prev;
}linkedlist;

linkedlist list[MAX_LIST];
int flag[MAX_LIST] = { 0, }; //1이면 할당된 상태, 0이면 비어있는 상태

void init(linkedlist* Head)
{
	Head->next = Head;
	Head->prev = Head;
	flag[0] = 1;
}
int isfull()
{
	int i = 0;
	for (; i < MAX_LIST; i++)
	{
		if (flag[i] == 0)
			return 0;
	}
	return 1;
}
void insert(linkedlist*prev_node,int number)
{
	int i=0;
	if (isfull())
	{
		printf("list is full\n");
		return;
	}
	for (; i < MAX_LIST; i++)
	{
		if (flag[i] == 0)
			break;
	}
	linkedlist* p = &list[i];
	p->lots = number;
	p->next = prev_node->next;
	p->prev = prev_node->next->prev;
	prev_node->next = p;
	prev_node->next->prev = p;
	flag[i] = 1;
}

void delete(linkedlist* delete_node)
{
	int i = 0;
	if (delete_node->next == delete_node->prev)
		return;

	else
	{
		for (; i < MAX_LIST; i++)
		{
			if (delete_node == &list[i])
				break;
		}
		linkedlist* p = &list[i];
		delete_node->prev->next = delete_node->next;
		delete_node->next->prev = delete_node->prev;
		flag[i] = 0;

	}

}

void print_list(linkedlist* Head)
{
	linkedlist* p = Head->next;
	for (; p != Head; p = p->next)
	{
		printf("%d ", p->lots);
	}

}

int main()
{
	srand(time(NULL));
	int lots = 0;
	int number = 0;
	printf("랜덤으로 숫자찾기\n");
	printf("찾고싶은 수(1-45)\: ");
	scanf("%d", &number);
	linkedlist* Head = &list[0];
	init(Head);
	for (int i = 1; i < 46; i++)
	{
		insert(Head, i);
	}
	for (int i = 1; i < 46; i++)
	{
		lots = rand() % 45 + 1;
		if (lots != number)
		{
			printf("%d x\n", lots);
			delete(&list[lots]);
			continue;
		}
		else
		{
			printf("%d o\n", lots);
			break;
		}
	}
	


}