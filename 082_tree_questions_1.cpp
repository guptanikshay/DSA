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

// MAX HEIGHT OF BINARY TREE
int maxDepth(Node *root)
{
    int count = 0;
    if (root == NULL)
        return count;
    count += 1;
    int l = maxDepth(root->left), r = maxDepth(root->right);
    if (l >= r)
        count += l;
    else
        count += r;
    return count;
}

// DIAMETER OF BINARY TREE
int diameterOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = maxDepth(root->left) + maxDepth(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
} // It has a time complexity of O(n^2), more optimal approach below
pair<int, int> diameterFast(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameterOfBinaryTree(Node *root)
{
    return diameterFast(root).first;
}

// CHECK WHETHER A BINARY TREE IS BALANCED
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
        return false;
    if (isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
} // This approach has a time complexity of O(n^2), more optimal approach below
pair<int, bool> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, bool> ans = make_pair(0, true);
        return ans;
    }
    pair<int, bool> left = solve(root->left);
    pair<int, bool> right = solve(root->right);
    bool leftAns = left.second;
    bool rightAns = right.second;
    bool diff = (abs(left.first - right.first) <= 1);
    pair<int, bool> ans;
    ans.first = max(left.first, right.first) + 1;
    ans.second = (leftAns && rightAns && diff);
    return ans;
}
bool isBalanced(Node *root)
{
    return solve(root).second;
}

// CHECK IF TWO BINARY TREES ARE SAME
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL || q == NULL)
        return false;
    bool d = (p->data == q->data);
    bool ans = (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    return (ans && d);
}

// CHECK IF ANY PATHSUM IS EQUAL TO THE GIVEN TARGET-SUM
bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}
bool solve(Node *root, int targetSum, int sum)
{
    if (sum == targetSum && isLeaf(root))
        return true;
    if (root == NULL)
        return false;
    bool ansLeft = false, ansRight = false;
    if (root->left)
        ansLeft = solve(root->left, targetSum, sum + root->left->data);
    if (root->right)
        ansRight = solve(root->right, targetSum, sum + root->right->data);
    return (ansLeft || ansRight);
}
bool hasPathSum(Node *root, int targetSum)
{
    if (root == NULL)
        return false;
    int sum = root->data;
    return solve(root, targetSum, sum);
}

// CHECK IF THE GIVEN TREE IS A SUM-TREE (Each is node is equal to the sum of its left subtree and right subtree)
pair<int, bool> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, bool> p = make_pair(0, true);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<int, bool> p = make_pair(root->data, true);
        return p;
    }
    pair<int, bool> left = solve(root->left), right = solve(root->right);
    pair<int, bool> ans;
    bool flag = (left.second && right.second);
    int sum = left.first + right.first;
    if (sum == root->data && flag)
        ans.second = true;
    else
        ans.second = false;
    ans.first = root->data + sum;
    return ans;
}
bool isSumTree(Node *root)
{
    return solve(root).second;
}
int main()
{

    return 0;
}