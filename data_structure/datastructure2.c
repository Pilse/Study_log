#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef int element;

typedef struct
{
    int* data;
    int capacity;
    int top;
}StackType;

void init_stack(StackType* s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = malloc(s->capacity * sizeof(StackType));

}

int is_empty(StackType* s)
{
    return (s->top == 0);

}

int is_full(StackType* s)
{
    return (s->top == MAX_STACK_SIZE);
}

void push(StackType* s, char item)
{
    if (s->top == MAX_STACK_SIZE)
    {
        s->capacity++;
        s->data = realloc(s->data, s->capacity * sizeof(StackType));
        printf("realloc\n");
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
    if (s->top == -1)
    {
        printf("underflow\n");
        exit(1);
    }
    else
    {
        return s->data[(s->top)--];
    }

}


int main()
{
    StackType s;
    char word[100];

    bool is_true = true;

    init_stack(&s);
    printf("input string\n");
    gets_s(word,100);
    for (int i = 0; i < strlen(word) / 2; i++)
         push(&s, word[i]);

    for (int i = (strlen(word))/2+1 ; i < strlen(word); i++)
    {
        if (pop(&s) != word[i])
        {
            printf("no\n");
            is_true = false;
            return;
        }

    }
    if (is_true == true)
        printf("yes");
    return 0;


}