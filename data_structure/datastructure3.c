#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100


int maze[6][6] =
{

};
typedef struct
{
    element data[100];
    int top;
}StackType;

typedef struct   
{
    int r;
    int c;
}element;

element here ={1,0};
element entry = {1,0};

void init_stack(StackType* s)
{
    s->top = -1;

}

int is_empty(StackType* s)
{
    return (s->top == -1);

}

int is_full(StackType* s)
{
    return (s->top == MAX_STACK_SIZE-1);
}

void push(StackType* s, element item)
{
    if (is_full)
    {
       printf("overflow\n");
    }
  else
  {
      s->data[++(s->top)]=item;
  }
  

}
void push_loc(StackType *s, int r, int c)
{
    if(r<0||c<0) return;
    if(maze[r][c] != '1' && maze[r][c] !='.')
    {
        element tmp;
        tmp.r=r;
        tmp.c=c;
        push(s,tmp);
    }
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
    int r,c;
    StackType s;

    init_stack(&s);
    here=entry;
    while(maze[here.r][here.c]!='x')
    {   
        r=here.r;
        c=here.c;

        push_loc(&s,r+1,c);
        push_loc(&s,r,c+1);
        push_loc(&s,r-1,c);
        push_loc(&s,r,c-1);

        here=pop(&s);
    }
}