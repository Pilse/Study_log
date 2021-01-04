#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define NUMBERS_OF_COUNTER 2
typedef struct
{
    int arrival_time;
    int service_time;
    int id;

}element;

typedef struct
{
    int front;
    int rear;
    element data[MAX_SIZE];
}QUEUE;


void error(char* message)
{
    printf(message);
    exit(1);
}

void init_queue(QUEUE* q)
{
    q->front = 0;
    q->rear = 0;
}

int is_empty(QUEUE* q)
{
    return (q->front == q->rear);
}

int is_full(QUEUE* q)
{
    return (q->front == ((q->rear) + 1) % MAX_SIZE);
}


void enqueue(QUEUE* q, element item)
{
    if (is_full(q))
    {
        error("queue is full\n");
        exit(1);
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = item;
    }


}

element dequeue(QUEUE* q)
{
    if (is_empty(q))
        error("queue is empty\n");
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
        return (q->data[q->front]);
    }


}
int main()
{
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time[MAX_SIZE] = { 0, };
    int service_customer[MAX_SIZE] = { 0, };
    QUEUE queue;
    init_queue(&queue);

    srand(time(NULL));

    for (int clock = 0; clock < minutes; clock++)
    {
        printf("current time: %d\n", clock);
        if ((rand() % 10) < 3)
        {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = (rand() % 3) + 1;
            enqueue(&queue, customer);
            printf("customer %d entered at %d. service time required : %d\n", customer.id, customer.arrival_time, customer.service_time);
        }
        for (int i = 1; i < NUMBERS_OF_COUNTER +1; i++)
        {
            if (service_time[i] > 0)
            {
                printf("customer %d is doing business (counter %d). %d minutes left.\n", service_customer[i], i, service_time[i]);
                service_time[i]--;                         
            }
            else
            {
                if (!is_empty(&queue))
                {
                    element customer;
                    customer = dequeue(&queue);
                    service_customer[i] = customer.id;
                    service_time[i] = customer.service_time;
                    printf("customer %d starts his business (counter %d). he waited %d minutes .\n", customer.id, i, clock - customer.arrival_time);
                    total_wait = total_wait + clock - customer.arrival_time;
                }
            }
        }
        printf("\n");
    }
        printf("total waiting time : %d \n", total_wait);
        return 0;
    
}
