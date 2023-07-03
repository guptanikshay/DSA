#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data\n";
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    root->data = data;
    cout << "For the left of " << data << " ";
    root->left = buildTree(root->left);
    cout << "For the right of " << data << " ";
    root->right = buildTree(root->right);
    return root;
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
void revLevelOrderTraversal(Node * root){
    stack <Node *> s;
    queue <Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        s.push(temp);
        if(temp==NULL){
            if(!q.empty())
            q.push(NULL);
        }
        else{
            if(temp->right)
            q.push(temp->right);
            if(temp->left)
            q.push(temp->left);
        }
    } 
    s.pop();
    while(!s.empty()){
        Node * temp = s.top();
        if(temp==NULL)
        cout<<"\n";
        else
        cout<<temp->data<<" ";
        s.pop();
    }
}
void inOrderTraversal(Node * root){
    if(root == NULL)
    return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
// void inOrderTraversal(Node * root){
//     stack <Node *> s;
//     Node * curr = root;
//     bool done = false;
//     while(!done){
//         if(curr!=NULL)
//         {
//             s.push(curr);
//             curr = curr->left;
//         }
//         else if(!s.empty()){
//             Node * temp = s.top();
//             s.pop();
//             cout<<temp->data<<" ";
//             curr = temp->right;
//         }
//         else
//         done = true;
//     }
// } // --> ITERATIVE
void preOrderTraversal(Node * root){
    if(root == NULL)
    return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left); 
    preOrderTraversal(root->right);
}
// void preOrderTraversal2(Node * root){
//     stack <Node *> s;
//     Node * curr = root;
//     s.push(curr);
//     while(!s.empty()){
//         Node * temp = s.top();
//         s.pop();
//         cout<<temp->data<<" ";
//         if(temp->right)
//         s.push(temp->right);
//         if(temp->left)
//         s.push(temp->left);
//     }
// } //--> ITERATIVE
void postOrderTraversal(Node * root){
    if(root == NULL)
    return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
// void postOrderTraversal(Node * root){
//     stack <Node*> s1, s2;
//     s1.push(root);
//     while(!s1.empty()){
//         Node * temp = s1.top();
//         s1.pop();
//         s2.push(temp);
//         if(temp->left)
//         s1.push(temp->left);
//         if(temp->right)
//         s1.push(temp->right);
//     }
//     while(!s2.empty()){
//         cout<<s2.top()->data<<" ";
//         s2.pop();
//     }
// } // --> ITERATIVE
int main()
{
    Node *root = buildTree(root);
    // 10 9 7 -1 -1 6 -1 -1 8 5 -1 -1 -1 
    cout<<"The Level Order Traversal of the tree is \n"; 
    levelOrderTraversal(root);
    cout<<"The Reverse Level Order Traversal of the tree is \n";
    revLevelOrderTraversal(root);
    cout<<"\n";
    cout<<"The InOrder Traversal of the tree is \n";
    inOrderTraversal(root);
    cout<<"\n";
    cout<<"The PreOrder Traversal of the tree is \n";
    preOrderTraversal(root);
    cout<<"\n";
    cout<<"The PostOrder Traversal of the tree is \n";
    postOrderTraversal(root);
    cout<<"\n";
    return 0;
}