#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist* next;
    struct linkedlist* prev;

}Linkedlist;

int count;
Linkedlist list[100];

void init(Linkedlist* Head)
{
    Head->data = 0;
    Head->next = Head;
    Head->prev = Head;
}

void error(char* message)
{
    perror(message);
 }

void insert(Linkedlist* node, int item)
{
    Linkedlist* new = &list[++count];
    new->data = item;
    new->next = node->next;
    new->prev = node;
    node->next->prev = new;
    node->next = new;
}

void delete(Linkedlist* node)
{
    if (node->next == node->prev)
        return;
    else
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }


}
void print_list(Linkedlist* Head)
{
    Linkedlist* p = list;
    p = Head->next;
    for (; p != Head; p = p->next)
    {
        printf("<- |%d| - >", p->data);
    }
    printf("\n");
}


int main()
{
    Linkedlist* Head = list;
    init(Head);
    for (int i = 0; i < 5; i++)
    {
        insert(Head, i);
        print_list(Head);
    }
    for (int i = 0; i < 5; i++)
    {
        delete(Head->next);
        print_list(Head);
    }

    return 0;
}