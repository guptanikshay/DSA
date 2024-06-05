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

// ZIG ZAG LEVEL ORDER TRAVERSAL
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool left = true;
    vector<int> row;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (!left)
                reverse(row.begin(), row.end());
            ans.push_back(row);
            row.clear();
            if (!q.empty())
                q.push(NULL);
            left = !left;
        }
        else
        {
            row.push_back(temp->data);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}

// BOUNDARY TRAVERSAL
void traverseLeft(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}
void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        ans.push_back(root->data);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);
    return ans;
}

// VERTICAL ORDER TRAVERSAL
vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(temp.first->data);
        if (temp.first->left)
            q.push(make_pair(temp.first->left, make_pair(hd - 1, lvl + 1)));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : nodes)
    {
        vector<int> hNodes;
        for (auto j : i.second)
        {
            sort(j.second.begin(), j.second.end());
            for (auto k : j.second)
                hNodes.push_back(k);
        }
        ans.push_back(hNodes);
    }
    return ans;
}
// Another Approach
vector<int> verticalOrder(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(temp.first->data);
        if (temp.first->left)
            q.push(make_pair(temp.first->left, make_pair(hd - 1, lvl + 1)));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

// TOP VIEW OF BINARY TREE
vector<int> topView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, int>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;
        if (nodes[hd].count(lvl) == 0)
            nodes[hd][lvl] = temp.first->data;
        if (temp.first->left)
            q.push(make_pair(temp.first->left, make_pair(hd - 1, lvl + 1)));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++)
        ans.push_back(it->second.begin()->second);
    return ans;
}
// Better code below
vector<int> topView2(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> topN;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        if (topN.find(temp.second) == topN.end())
            topN[temp.second] = temp.first->data;
        if (temp.first->left)
            q.push(make_pair(temp.first->left, temp.second - 1));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, temp.second + 1));
    }
    for (auto i : topN)
        ans.push_back(i.second);
    return ans;
}

// BOTTOM VIEW OF BINARY TREE
vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, map<int, int>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl] = temp.first->data;
        if (temp.first->left)
            q.push(make_pair(temp.first->left, make_pair(hd - 1, lvl + 1)));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++)
        ans.push_back((--it->second.end())->second);
    return ans;
} // Better code below
vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> nodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        nodes[hd] = temp.first->data;
        if (temp.first->left)
            q.push(make_pair(temp.first->left, hd - 1));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, hd + 1));
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// LEFT VIEW OF A BINARY TREE
void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// RIGHT VIEW OF BINARY TREE
void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// DIAGONAL TRAVERSAL
void solve(Node *root, map<int, vector<int>> &diags, int d)
{
    if (!root)
        return;
    diags[d].push_back(root->data);
    solve(root->left, diags, d + 1);
    solve(root->right, diags, d);
}
vector<int> diagonal(Node *root)
{
    // your code here
    map<int, vector<int>> diags;
    vector<int> ans;
    int d = 0;
    solve(root, diags, d);
    for (auto i : diags)
    {
        for (auto j : i.second)
            ans.push_back(j);
    }
    return ans;
}
int main()
{

    return 0;
}