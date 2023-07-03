#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// Approach 1: Using Recursion with TC O(n) and SC O(n)
// void helper(Node *&prev, Node *root)
// {
//     if (!root)
//         return;
//     helper(prev, root->right);
//     helper(prev, root->left);
//     root->right = prev;
//     root->left = NULL;
//     prev = root;
// }
// void flatten(Node *root)
// {
//     Node *prev = NULL;
//     helper(prev, root);
// }

// Approach 2: Using Morris Traversal with TC O(n) and SC O(1)
void flatten(Node *root)
{
    Node *curr = root, *temp;
    while (curr != NULL)
    {
        if (curr->left)
        {
            temp = curr->left;
            while (temp->right)
                temp = temp->right;
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main()
{

    return 0;
}