// Using Morris Traversal we can get the inorder traversal with using stack or recursion and hence solving the problem in O(1) extra space. The algorithm is as follows
// 1. Initialize current as root
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
//       a) Find rightmost node in current left subtree OR
//               node whose right child == current.
//          If we found right child == current
//              a) Update the right child as NULL of that node whose right child is current
//              b) Print current’s data
//              c) Go to the right, i.e. current = current->right
//          Else
//              a) Make current as the right child of that rightmost
//                 node we found; and
//              b) Go to this left child, i.e., current = current->left
#include <bits/stdc++.h>
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

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter data for root node\n";
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int leftdata;
        cout << "Enter data for left node of " << temp->data << "\n";
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        int rightdata;
        cout << "Enter data for right node of " << temp->data << "\n";
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

void morrisInorder(Node *root)
{
    Node *curr = root, *temp;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
                temp = temp->right;
            if (temp->right == curr)
            {
                temp->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
            else
            {
                temp->right = curr;
                curr = curr->left;
            }
        }
    }
    cout << "\n";
}
void morrisPreorder(Node *root)
{
    Node *curr = root, *temp;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
                temp = temp->right;
            if (temp->right == curr)
            {
                temp->right = NULL;
                curr = curr->right;
            }
            else
            {
                temp->right = curr;
                cout << curr->data << " ";
                curr = curr->left;
            }
        }
    }
    cout << "\n";
}
void morrisRevPostorder(Node *root) // This algo gives reverse post order traversal of the tree. The answer can be reversed to get the actual postorder traversal.
{
    Node *curr = root, *temp;
    while (curr != NULL)
    {
        if(curr->right==NULL){
            cout<<curr->data<<" ";
            curr = curr->left;
        }
        else{
            temp = curr->right;
            while(temp->left!=NULL && temp->left!=curr)
            temp = temp->left;
            if(temp->left==curr){
                temp->left=NULL;
                curr = curr->left;
            }
            else{
                temp->left = curr;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
    cout << "\n";
}
int main()
{
    Node *root;
    // 10 9 8 7 6 5 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);  
    // morrisInorder(root);
    // morrisPreorder(root);
    morrisRevPostorder(root);
    return 0;
}