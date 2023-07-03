#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// CONSTRUCT TREE FROM INORDER AND PREORDER TRAVERSAL
TreeNode *solve(vector<int> &preorder, vector<int> inorder, int start, int end)
{
    if (preorder.size() == 0 || end < start)
        return NULL;
    int ele = preorder.back();
    preorder.pop_back();
    TreeNode *root = new TreeNode(ele);
    int index = start;
    while (index <= end)
    {
        if (inorder[index] == ele)
            break;
        index++;
    }
    root->left = solve(preorder, inorder, start, index - 1);
    root->right = solve(preorder, inorder, index + 1, end);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    TreeNode *root;
    reverse(preorder.begin(), preorder.end());
    root = solve(preorder, inorder, 0, inorder.size() - 1);
    return root;
} // Another approach below which takes less time but memory limit might exceed in this one
TreeNode *solve(vector<int> &preorder, vector<int> inorder, int start, int end, map<int, int> nodeIndex)
{
    if (preorder.size() == 0 || end < start)
        return NULL;
    int ele = preorder.back();
    preorder.pop_back();
    TreeNode *root = new TreeNode(ele);
    int index = nodeIndex[ele];
    root->left = solve(preorder, inorder, start, index - 1, nodeIndex);
    root->right = solve(preorder, inorder, index + 1, end, nodeIndex);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    TreeNode *root;
    reverse(preorder.begin(), preorder.end());
    map<int, int> nodeIndex;
    for (int i = 0; i < inorder.size(); i++)
        nodeIndex[inorder[i]] = i;
    root = solve(preorder, inorder, 0, inorder.size() - 1, nodeIndex);
    return root;
}
int main()
{

    return 0;
}