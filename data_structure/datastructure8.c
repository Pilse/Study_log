#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int key;
    struct treenode* left;
    struct treenode* right;

}treenode;


treenode* search(treenode* root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else if (key > root->key)
        return search(root->right, key);
}
treenode* new_node(int key)
{
    treenode* node = malloc(sizeof(treenode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
treenode* insert_node(treenode* root, int key)
{
    treenode* temp = root;
    if (root == NULL)
    {
        return new_node(key);
    }
    if (key < root->key)
        root->left= insert_node(root->left, key);
    else if (key > root->key)
        root->right= insert_node(root->right, key);
    return root;
}
treenode* min_value_node(treenode* node)
{
    if (node == NULL)
        return node;
    else
        return min_value_node(node->left);
}
treenode* delete_node(treenode* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left=delete_node(root->left, key);
    else if (key > root->key)
        root->right=delete_node(root->right, key);
    if (key == root->key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            treenode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            treenode* temp = root->left;
            free(root);
            return temp;
        }
    }
}
void inorder(treenode* root)
{
    if (root)
    {
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}


int main()
{
    treenode* root = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);
    inorder(root);
    printf("\n");
    delete_node(root,20);
    inorder(root);
    printf("\n");
    if (search(root, 30) != NULL)
        printf("30 is in tree \n");

    return 0;

}