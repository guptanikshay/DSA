#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Recursive approach to search for a value in a binary search tree. TC: O(n) and SC: O(n)
Node *searchBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->data == val)
        return root;
    if (val < root->data)
    {
        root->left = searchBST(root->left, val);
        return root->left;
    }
    else
    {
        root->right = searchBST(root->right, val);
        return root->right;
    }
}

// Iterative Approach with TC: O(n) and SC: O(1)
// Node *searchBST(Node *root, int val)
// {
//     while (root != NULL && root->data != val)
//     {
//         if (val < root->data)
//             root = root->left;
//         else
//             root = root->right;
//     }
//     return root;
// }

// Code for deletion of a node in BST
int minVal(Node *root)
{
    Node *temp = root;
    while (temp->left)
        temp = temp->left;
    return temp->data;
}
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;
    else if (root->data == key)
    {
        if (!root->right && !root->left)
            return NULL;
        else if (!root->right && root->left)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right && !root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    else
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
}
int main()
{

    return 0;
}