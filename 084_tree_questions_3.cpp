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
    pair<int, int> ans;
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
    int sum = 0, count = 0;
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
int main()
{

    return 0;
}