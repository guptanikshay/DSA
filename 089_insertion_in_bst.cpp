// A BST or a Binary Search Tree is tree in which for every node, the data of right node is greater than the data of node and the data of left node is smaller than the data of the node. The inorder traversal of a BST is in ascending order.
// Below is the code of insertion in a BST
#include <iostream>
#include <queue>
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

// We recursively find the correct position of the data to be inserted into the tree, i.e., we check the root node and if its NULL, we insert the data right there and if its NON-NULL we check whether the data is smaller than root->data and if it is we call the insert for root->left. If its larger than root->data we call the insert for root->right.
Node *insertInBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
    return;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << "\n";
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    return 0;
}