#include <iostream>

using namespace std;

int arr[100000];
int heapSize;

void insertHeap(int input)
{
    arr[++heapSize] = input;

    int child = heapSize;
    int parent = 0;
    int temp = 0;

    while(child > 1)
    {
        parent = child / 2;

        if(arr[parent] > arr[child])
        {
            temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;

            child = parent;
        }
        else
            break;
    }
}
int deleteHeap()
{
    int returnValue = arr[1];

    int parent = 1;
    int child = 0;
    int temp = 0;
    arr[parent] = arr[heapSize--];

    while(parent * 2 <= heapSize)
    {
        child = parent * 2;
        if(arr[child] > arr[child + 1])
            child++;
        if(arr[child] < arr[parent])
        {
            temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;

            parent = child;
        }
        else
            break;
    }
    
    return returnValue;

}

int main()
{
    int n;
    scanf("%d",&n);

    int input =0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&input);

        if(input == 0)
        {
            if(heapSize == 0)
                printf("0\n");
            else
                printf("%d\n",deleteHeap());
        }
        else
            insertHeap(input);
    }
}
