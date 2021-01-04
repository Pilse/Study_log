#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 7
typedef struct list
{
    int key;
    struct list* link;
}list;

list* hash_table[TABLE_SIZE];


int hash_function(int key)
{
    return key % TABLE_SIZE;
}

void hash_chain_add(int key,list* ht[])
{
    int hash_value = hash_function(key);
    list* node = ht[hash_value];
    list* node_before = NULL;
    for (; node; node = node_before = node ,node=node->link)
    {
        if (node->key == key)
        {
            fprintf(stderr, "already exsited key\n");
            return;
        }
    }
    list* ptr = malloc(sizeof(list));
    ptr->key = key;
    ptr->link = NULL;
    if (node_before)
        node_before->link = ptr;
    else
        ht[hash_value] = ptr;
   
}

void hash_chain_search(int key, list* ht[])
{
    int hash_value = hash_function(key);
    list* node = ht[hash_value];
    for (node; node; node = node->link)
    {
        if (node->key == key)
        {
            printf("탐색성공\n");
            return;
        }
    }
    printf("탐색실패\n");

}

void hash_chain_print(list* ht[])
{
    list* node;
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d] -> ", i);

        for (node = ht[i]; node; node = node->link)
        {
            printf("%d -> ", node->key);
        }
        printf("\n");
    }
 }
int main()
{
    int data[] = { 8,1,9,6,13 };
    list l;
    for (int i = 0; i < 5; i++)
    {
        l.key = data[i];
        hash_chain_add(l.key,hash_table);
    }
    hash_chain_print(hash_table);
    for (int i = 0; i < 5; i++)
    {
        l.key = data[i];
        hash_chain_search(l.key, hash_table);
    }

}