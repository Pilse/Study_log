#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

typedef struct BST
{
    int num;
    struct BST* left;
    struct BST* right;

}BST;
BST* new_node(int num)
{
    BST* temp = new BST;
    temp->num = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;

}

BST* insert(BST* root, int num)
{
    if (root == NULL)
        return new_node(num);
    if (num < root->num)
        root->left = insert(root->left, num);
    else if (num > root->num)
        root->right = insert(root->right, num);
    return root;
}

BST* search(BST* root, int num)
{
    if (root == NULL)
        return NULL;
    if (num == root->num)
        return root;
    else if (num < root->num)
        return search(root->left, num);
    else
        return search(root->right, num);
}

int main()
{
    int number_of_integers = 0;
    int number_of_search = 0;
    BST* root = NULL;
    cin >> number_of_integers;
    int* integer_array = new int[number_of_integers];
    for (int i = 0; i < number_of_integers; i++)
    {
        cin >> integer_array[i];
        root = insert(root, integer_array[i]);
    }
    cin >> number_of_search;
    int* search_array = new int[number_of_search];
    for (int i = 0; i < number_of_search; i++)
    {
        cin >> search_array[i];
        if (search(root, search_array[i]) != NULL)
            cout << "1" << "\n";
        else
            cout << "0" << "\n";
    }

}