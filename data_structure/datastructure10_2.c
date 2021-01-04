#include <stdio.h>
#define MAX_QUEUE 50
#define MAX_VERTICES 50
typedef struct GraphType
{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
int visited[MAX_VERTICES];

void init(GraphType* g)
{
    g->n=0;
    for(int r=0;r<MAX_VERTICES;r++)
    {
        for(int c=0;c<MAX_VERTICES;c++)
        {
            g->adj_mat[r][c]=0;
        }
    }

}
void insert_vertex(GraphType* g,int v)
{
    g->n++;

}
void insert_edge(GraphType*g,int start,int end)
{
    g->adj_mat[start][end]=1;
    g->adj_mat[end][start]=1;

}

int queue[MAX_QUEUE];
int front,rear;
void enqueue(int data)
{
    queue[rear++]=data;

}

int dequeue()
{
    int result = queue[front++];
    return result;
}
int is_empty()
{
    if(front==rear)
    return 1;
    else
    return 0;

}
void bfs(GraphType* g,int v)
{
    visited[v]=1;
    enqueue(v);
    printf("%d -> ",v);
    while(!is_empty)
    {
        int w=dequeue();
        for(int i=0;i<g->n;i++)
        {
            if(g->adj_mat[w][i]==1&&!visited[w])
            {
                enqueue(i);
                visited[i]=1;
                printf("%d -> ",i);

            }
        }

    }

}
int main()
{

}