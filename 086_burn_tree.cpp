// Calculate the minimum time required to burn a tree when starting from a target node and in one second each node connected to the target gets burnt.
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
Node *addParent(Node *root, map<Node *, Node *> &parent, int target)
{
    Node *targ = NULL;
    queue<Node *> q;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
            targ = front;
        if (front->left)
        {
            parent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            parent[front->right] = front;
            q.push(front->right);
        }
    }
    return targ;
}
int burnTime(Node *targ, map<Node *, Node *> &parent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    int time = 0;
    q.push(targ);
    visited[targ] = true;
    while (!q.empty())
    {
        bool flag = 0;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = true;
                flag = 1;
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                flag = 1;
            }
            if (parent[front] && !visited[parent[front]])
            {
                q.push(parent[front]);
                visited[parent[front]] = true;
                flag = 1;
            }
        }
        if (flag)
            time++;
    }
    return time;
}
int minTime(Node *root, int target)
{
    // Your code goes here
    map<Node *, Node *> parent;
    Node *targ = addParent(root, parent, target);
    return burnTime(targ, parent);
}
int main()
{

    return 0;
}