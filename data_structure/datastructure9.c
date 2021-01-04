#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
//우선순위 큐(priority queue)

typedef struct
{
    int key;
}element;
typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
}heaptype;

heaptype* create()
{
    heaptype* temp = malloc(sizeof(heaptype));
    return temp;
}
heaptype* init(heaptype* h)
{
    h->heap_size = 0;
    return h;

}
void insert(heaptype* h, element x)
{
    int child = ++h->heap_size;

    if (h->heap_size == 200)
    {
        printf("heap is full");
        exit(-1);
    }
    h->heap[child].key = x.key;
    while (1)
    {
        if (child == 1)
            break;
        int parent = child / 2;

        if (h->heap[parent].key >= h->heap[child].key)
            break;
        else
        {
            int temp = 0;
            temp = parent;
            parent = child;
            child = temp;
            temp = h->heap[child].key;
            h->heap[child].key = h->heap[parent].key;
            h->heap[parent].key = temp;
        }
    }

}
int delete(heaptype* h)
{
    int parent = 1;
    int result = h->heap[parent].key;
    h->heap[parent].key = h->heap[h->heap_size].key;
    h->heap_size--;

    while (1)
    {
        int child = parent * 2;
        if (h->heap_size /2== parent/2 )
            break;

        if (h->heap[child].key < h->heap[child + 1].key)
            child++;
        if (h->heap[parent].key < h->heap[child].key)
        {
            int temp = 0;
            temp = parent;
            parent = child;
            child = temp;
            temp = h->heap[child].key;
            h->heap[child].key = h->heap[parent].key;
            h->heap[parent].key = temp;
        }
        else
        {
            break;
        }



    }
    return result;



}


int main()
{
    element e1[] = { 1,2,3,4,5,6,7,8,9 };
    int e4, e5, e6;
    heaptype* heap;

    heap = create(); 	// 히프 생성
    init(heap);	// 초기화

                // 삽입
    for (int i = 0; i < 9; i++)
    {
        insert(heap, e1[i]);
    }
    // 삭제
    e4 = delete(heap);
    printf("< %d > ", e4);
    e5 = delete(heap);
    printf("< %d > ", e5);
    e6 = delete(heap);
    printf("< %d > \n", e6);

    free(heap);

}