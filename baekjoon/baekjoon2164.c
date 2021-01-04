#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 500001

int queue[MAX];
int front = 0;
int rear = 0;

void insert(int num)
{
    rear = (rear + 1) % MAX;
    queue[rear] = num;

}

void delete()
{
    front = (front + 1) % MAX;
}

void front_to_rear()
{
    rear = (rear + 1) % MAX;
    queue[rear] = queue[front+1];
    front = (front +1) % MAX;
   
}



int main()
{
    int N = 0;
    scanf("%d", &N);
    int distance = 0;
    for (int i = 1; i <= N; i++)
    {
        insert(i);
    }
    distance = (rear - front + MAX) % MAX;
    while (distance != 1)
    {
        delete();
        if ((rear - front + MAX) % MAX != 1)
            front_to_rear();
        else
            break;
        distance = (rear - front + MAX) % MAX;
    }

    printf("%d", queue[rear]);
   
}
