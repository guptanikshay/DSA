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

// Dekh apne tree ko apn levels ke according dekhenge aur top level se start krte hue saare levels print kr denge. Iske liye apn queue ka use krenge, sabse pehle usme root push kr denge aur fir apna algo start hoga, and jb tk apna queue empty nhi ho jata tb tk apn ye algo chalne denge aur aisa krne ke liye apn ek while loop laga denge. Toh loop m enter hone ke baad apn queue m se ek node pop krenge aur uska data print kr denge, fir check krenge ki iska left child NON-NULL hai kya (dhyaan rhe pehle left check krna hai) aur agr aisa hai to usko queue m insert kr denge aur fir same process right child ke saath repeat krenge. Ab agr apne queue m koi node push hui hogi to while loop chlta rhega aur end m apne ko level order traversal mil jayega. But there is one problem, all the levels will be printed on the same line and that does not look like an appealing LOT. To tackle this, we use a separator (NULL), first of all we insert a NULL right after we push the root node into the queue. Here NULL tells us that one level is completed. Now inside the while loop the same process continues, we pop the node and push its left and right children into the queue, but in the second iteration, when we pop from the queue we get a NULL, which tells us that this level is over so we print a new line and if the queue is still non empty, it implies that in the last iteration we pushed all the nodes of the next level into the queue, so we insert a NULL again to get a new line after this level and the while loop continues.
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

// No new concept here, we simply used a stack to reverse the original LOT. Instead of printing the nodes, we pushed them into a stack, and in the end, popped and printed them all to get the reverse LOT.
void revLevelOrderTraversal(Node *root)
{
    stack<Node *> s;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp);
        if (temp == NULL)
        {
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    s.pop();
    while (!s.empty())
    {
        Node *temp = s.top();
        if (temp == NULL)
            cout << "\n";
        else
            cout << temp->data << " ";
        s.pop();
    }
}
void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
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
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
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
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
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
    cout << "The Level Order Traversal of the tree is \n";
    levelOrderTraversal(root);
    cout << "The Reverse Level Order Traversal of the tree is \n";
    revLevelOrderTraversal(root);
    cout << "\n";
    cout << "The InOrder Traversal of the tree is \n";
    inOrderTraversal(root);
    cout << "\n";
    cout << "The PreOrder Traversal of the tree is \n";
    preOrderTraversal(root);
    cout << "\n";
    cout << "The PostOrder Traversal of the tree is \n";
    postOrderTraversal(root);
    cout << "\n";
    return 0;
}