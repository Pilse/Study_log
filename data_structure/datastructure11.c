#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init()
{
    memset(parent, -1, MAX_VERTICES);
}
int set_find(int current)
{
    if (parent[current] == -1)
        return current;
    else
    {
        while (parent[current] != -1)
        {
            current = parent[current];
        }
        return current;
    }


}
void set_union(int m, int n)
{
    int set1, set2;
    set1 = set_find(m);
    set2 = set_find(n);
    if (set1 != set2)
        parent[set1] = set2;
}
typedef struct Edge
{
    int start, end, weight;

}Edge;

typedef struct GraphType
{
    int n;
    Edge edges[2 * MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g)
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) 
    {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }

}
void insert_edge(GraphType* g, int n, int m, int weight)
{
    g->edges[g->n].start = n;
    g->edges[g->n].end = m;
    g->edges[g->n].weight = weight;
    g->n++;

}
int compare(const void* a, const void* b)
{
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
    return(x->weight - y->weight);

}

void kruskal(GraphType* g)
{
    int cnt = 0;
    int i = 0;
    set_init();
    qsort(g->edges, g->n, sizeof(Edge), compare);
     while (cnt != (g->n-1))
    {
        int u, v;
        u = set_find(g->edges[i].start);
        v = set_find(g->edges[i].end);
        if (u != v)
        {
            cnt++;
            set_union(u, v);
            printf("(%d,%d)\n", g->edges[i].start, g->edges[i].end);
        }
        i++;

    }

}


int main()
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g);
    free(g);
    return 0;


}
