#include <iostream>
using namespace std;

int heap[200010] = { 0, };
int heap_size = 0;
void insert_heap(int num)
{
	heap[++heap_size] = num;
	int child = heap_size;
	while (1)
	{
		if (child == 1)
			break;
		int parent = child / 2;
		if (heap[parent] < heap[child])
		{
			int temp = 0;
			temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
			child = parent;
		}
		else
			break;

	}

}

int delete_heap()
{
	int parent = 1;
	int return_value = heap[parent];
	heap[parent] = heap[heap_size];
	heap[heap_size--] = 0;
	while (1)
	{
		int child = parent * 2;
		if (parent / 2 == heap_size / 2)
			break;
		if (heap[child] < heap[child + 1]) child++;
		if (heap[parent] < heap[child])
		{
			int temp = 0;
			temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
			parent = child;
		}
		else
			break;

	}
	return return_value;


}
int main()
{
	int N;
	int input = 0;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
        
		scanf("%d",&input);
		if (input == 0)
		{
			if (heap_size == 0)
				printf("0\n");
			else
				printf("%d\n", delete_heap());
		}
		else
			insert_heap(input);
	}
	return 0;
}