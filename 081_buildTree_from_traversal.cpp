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
void buildFromLevelOrder(Node * &root){
    queue <Node *> q;
    int data;
    cout<<"Enter data for root node\n";
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        int leftdata;
        cout<<"Enter data for left node of "<<temp->data<<"\n";
        cin>>leftdata;
        if(leftdata!=-1){
        temp->left = new Node(leftdata);
        q.push(temp->left);
        }
        int rightdata;
        cout<<"Enter data for right node of "<<temp->data<<"\n";
        cin>>rightdata;  
        if(rightdata!=-1){
        temp->right = new Node(rightdata);
        q.push(temp->right);
        }
    }  
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
int main(){
    Node * root;
    // 10 9 8 7 6 5 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}