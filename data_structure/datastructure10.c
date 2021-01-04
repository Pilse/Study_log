#include <stdio.h>
#include <stdlib.h>
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

void dfs_mat(GraphType* g,int b)
{
    visited[b]=1;
    printf("%d->",b);
    for(int i=0;i<g->n;i++)
    {
        if((g->adj_mat[b][i]==1)&&(!visited[i]))
        {
            dfs_mat(g,i);
        }
    }

}
int main ()
{
    GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i<4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;

    

}
