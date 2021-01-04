#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100
//use node (by pointer) -> linked list

typedef struct LinkedList
{
    int data;
    struct LinkedList* link;

}LinkedList;

void error(char* message)
{
    printf(message);
    exit(1);

}

LinkedList* insert_first(LinkedList* head, int value)
{
    LinkedList* p = malloc(sizeof(LinkedList));
    p->data = value;
    p->link = head;
    return p;
}

void insert(LinkedList* pre, int value)
{
    LinkedList* p = malloc(sizeof(LinkedList));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
}

LinkedList* delete_first(LinkedList* head)
{
    LinkedList* p = malloc(sizeof(LinkedList));
    p = head->link;
    return p;
}

void delete(LinkedList* pre)
{
    LinkedList* p = malloc(sizeof(LinkedList));
    p = pre->link;
    pre->link = pre->link->link;
    free(p);
}

void print_list(LinkedList* head)
{
    LinkedList* p = malloc(sizeof(LinkedList));
    p = head;
    for (p; p; p = p->link)
    {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int search_list(LinkedList* head,int item)
{
    LinkedList* p = malloc(sizeof(LinkedList));
    p = head;
    int i = 0;
    for (p; p;p= p->link)
    {
        i++;
        if (p->data == item)
        {
            printf("find %d at %d\n", item,i);
            return 0;
        }
    }
    printf("no %d in list\n", item);
    return 0;
}

int main()
{
    LinkedList* Head = NULL;
    for (int i = 0; i < 5; i++)
    {
        Head = insert_first(Head, i);
        print_list(Head);
    }
    insert(Head->link->link, 7);
    print_list(Head);
    search_list(Head, 4);

}