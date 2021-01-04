#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct studentinfo
{
    char ID[20];
    char name[100];
    int score;
}studentinfo;

typedef struct linkedlist
{
    studentinfo data;
    struct linkedlist* next;
    struct linkedlist* prev;

}Linkedlist;

Linkedlist list[MAX];
int flag[MAX] = { 0, };

void init(Linkedlist* Head)
{
    Head->next = Head;
    Head->prev = Head;
    flag[0] = 1;
}

void error(char* message)
{
    perror(message);
}

void insert(Linkedlist* node, studentinfo item)
{
    int i = 1;
    for (; i < MAX; i++)
    {
        if (flag[i] == 0)
            break;
    }
    Linkedlist* new = &list[i];
    new->data = item;
    new->next = node->next;
    new->prev = node;
    node->next->prev = new;
    node->next = new;
    flag[i] = 1;
}

void delete(Linkedlist* node)
{
    if (node->next == node->prev)
        return;
    int i = 0;
    for (; i < MAX; i++)
    {
        if (node == &list[i])
            break;
    }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        flag[i] = 0;

}
void print_list(Linkedlist* Head)
{
    Linkedlist* p;
    p = Head->next;
    for (; p != Head; p = p->next)
    {
        printf("%s %s 점수:%d점\n", p->data.ID,p->data.name,p->data.score);
    }
    printf("\n");
}


int main()
{
    Linkedlist* Head = &list[0];
    int i=0;
    
    init(Head);
    printf("몇명의 학생 점수를 입력하시겠습니까?\n");
    scanf("%d", &i);
    for (int x = 0; x < i; x++)
    {
        studentinfo temp;
        printf("학번:");
        scanf("%s", temp.ID);
        printf("이름:");
        scanf("%s", temp.name);
        printf("점수:");
        scanf("%d", &temp.score);
        insert(Head, temp);
        printf("\n");
    }
    print_list(Head);
    return 0;
}
