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

// SUM OF LONGEST BLOODLINE (From root to leaf) OF A TREE
pair<int, int> maxDepthSum(Node *root)
{
    pair<int, int> ans; // First value stores depth and second value stores the sum
    ans.first = 0;
    ans.second = 0;
    if (!root)
        return ans;
    ans.first += 1;
    ans.second += root->data;
    pair<int, int> left = maxDepthSum(root->left), right = maxDepthSum(root->right);
    if (left.first > right.first)
    {
        ans.second += left.second;
        ans.first += left.first;
    }
    else if (left.first == right.first)
    {
        ans.first += left.first;
        if (left.second >= right.second)
            ans.second += left.second;
        else
            ans.second += right.second;
    }
    else
    {
        ans.second += right.second;
        ans.first += right.first;
    }
    return ans;
}
int sumOfLongRootToLeafPath(Node *root)
{
    // code here
    pair<int, int> ans = maxDepthSum(root);
    return ans.second;
}

// LOWEST COMMON ANCESTOR OF A BINARY TREE
void traverseFind(Node *root, Node *n, vector<Node *> &ans, bool &found)
{
    if (!root)
        return;
    if (root == n)
    {
        found = true;
        ans.push_back(root);
        return;
    }
    if (!found)
    {
        traverseFind(root->left, n, ans, found);
        if (!found)
            traverseFind(root->right, n, ans, found);
    }
    if (found)
        ans.push_back(root);
}
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root)
        return NULL;
    vector<Node *> pNodes;
    vector<Node *> qNodes;
    bool foundP = false, foundQ = false;
    traverseFind(root, p, pNodes, foundP);
    traverseFind(root, q, qNodes, foundQ);
    int pStart = 0, qStart = 0;
    if (pNodes.size() > qNodes.size())
    {
        pStart = pNodes.size() - qNodes.size();
    }
    else if (qNodes.size() > pNodes.size())
    {
        qStart = qNodes.size() - pNodes.size();
    }
    while (pStart < pNodes.size() && qStart < qNodes.size())
    {
        if (pNodes[pStart] == qNodes[qStart])
            break;
        pStart++;
        qStart++;
    }
    if (pStart > pNodes.size() || qStart > qNodes.size())
        return NULL;
    return qNodes[qStart];
} // Better approach below
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root || root == p || root == q)
        return root;
    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL)
        return root;
    else if (left == NULL && right != NULL)
        return right;
    else if (left != NULL && right == NULL)
        return left;
    else
        return NULL;
}

// K SUM PATHS
void solve(Node *root, int target, vector<long long int> path, int &count)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    solve(root->left, target, path, count);
    solve(root->right, target, path, count);
    long long int sum = 0, n = path.size();
    for (int i = n - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == target)
            count++;
    }
    path.pop_back();
}
int pathSum(Node *root, int targetSum)
{
    vector<long long int> path;
    int count = 0;
    solve(root, targetSum, path, count);
    return count;
}

// Kth ANCESTOR OF A NODE
void getPath(Node *root, int node, vector<int> &path, bool &found)
{
    if (root == NULL)
        return;
    if (root->data == node)
    {
        found = true;
        path.push_back(root->data);
        return;
    }
    if (!found)
    {
        getPath(root->left, node, path, found);
        if (!found)
            getPath(root->right, node, path, found);
    }
    if (found)
        path.push_back(root->data);
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int> path;
    bool found = false;
    getPath(root, node, path, found);
    if (k < path.size())
        return path[k];
    return -1;
}
// Another approach below
Node *solve(Node *root, int node, int &k)
{
    if (!root || root->data == node)
        return root;
    Node *left = solve(root->left, node, k);
    Node *right = solve(root->right, node, k);
    if (left != NULL && !right)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *a = solve(root, node, k);
    if (!a || a->data == node)
        return -1;
    return a->data;
}

// MAXIMUM SUM OF NON ADJACENT NODES
pair<int, int> solve(Node *root)
{
    pair<int, int> res;
    if (root == NULL)
    {
        res = make_pair(0, 0);
        return res;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

// MINIMUM HEIGHT TREES: Given is a graph in which each node is connected to every other node only through a single path, that is, for n nodes there are n-1 edges. We need to find all the nodes which when considered as root give minimum height of tree.
// MY APPROACH (BRUTE FORCE, TLE)
// int getHeight(vector<vector<int>> &adj, int root, int n)
// {
//     queue<int> q;
//     vector<int> vis(n, 0);
//     int height = 0;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         while (size--)
//         {
//             int node = q.front();
//             q.pop();
//             vis[node] = 1;
//             for (auto nbr : adj[node])
//             {
//                 if (!vis[nbr])
//                     q.push(nbr);
//             }
//         }
//         height++;
//     }
//     return height;
// }
// vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
// {
//     vector<vector<int>> adj(n);
//     for (auto i : edges)
//     {
//         adj[i[0]].push_back(i[1]);
//         adj[i[1]].push_back(i[0]);
//     }
//     vector<int> height(n);
//     int mini = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         height[i] = getHeight(adj, i, n);
//         mini = min(height[i], mini);
//     }
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         if (height[i] == mini)
//             ans.push_back(i);
//     }
//     return ans;
// }

int main()
{

    return 0;
}