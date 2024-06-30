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

// Code for deletion of a node in BST. The below function return the root node of tree after deletion.
// Deletion in BST has 3 cases depending on the number of children the nodeToDelete has (0, 1 or 2). In case of 0 children, we simply return NULL from that point. In case of 1 child (the child might also be the root node of a sub-tree), we return that child node (whether left or right, doesn't matter), and point the nodeToDelete to NULL. What we did here is that we pointed nodeToDelete's parent's left (or right) to the child of nodeToDelete, and hence omitting nodeToDelete from the tree. In case of 2 children, there are two ways to delete the node, either we can replace it with the maximum value in its left subtree or we can replace it with the minimum value in its right subtree. In the first approach, we change the data of nodeToDelete with the maximum value in its left subtree and call the delete function to delete this maximum value in the left subtree, which is handled recursively. Similarly, in second approach after replace the nodeToDelete's data we call the delete function to delete the maximum value in right subtree.
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