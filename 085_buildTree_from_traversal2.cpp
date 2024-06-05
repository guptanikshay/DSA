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
}

// Another approach below which takes less time but memory limit might exceed in this one
// TreeNode *solve(vector<int> &preorder, vector<int> inorder, int start, int end, map<int, int> nodeIndex)
// {
//     if (preorder.size() == 0 || end < start)
//         return NULL;
//     int ele = preorder.back();
//     preorder.pop_back();
//     TreeNode *root = new TreeNode(ele);
//     int index = nodeIndex[ele];
//     root->left = solve(preorder, inorder, start, index - 1, nodeIndex);
//     root->right = solve(preorder, inorder, index + 1, end, nodeIndex);
//     return root;
// }
// TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
// {
//     TreeNode *root;
//     reverse(preorder.begin(), preorder.end());
//     map<int, int> nodeIndex;
//     for (int i = 0; i < inorder.size(); i++)
//         nodeIndex[inorder[i]] = i;
//     root = solve(preorder, inorder, 0, inorder.size() - 1, nodeIndex);
//     return root;
// }

// CONSTRUCT TREE FROM INORDER AND POSTORDER TRAVERSAL
// Approach remains same, only differences are that here we won't reverse the postorder vector because the last element of post order is root node, and recursive call for right subtree will come first, because while traversing the postorder from behind, we encounter right subtree nodes before the left subtree nodes.
// TreeNode *solve(vector<int> inorder, vector<int> &postorder, int start, int end)
// {
//     if (postorder.size() == 0 || end < start)
//         return NULL;
//     int ele = postorder.back();
//     postorder.pop_back();
//     TreeNode *root = new TreeNode(ele);
//     int index = start;
//     while (start <= end)
//     {
//         if (inorder[index] == ele)
//             break;
//         index++;
//     }
//     root->right = solve(inorder, postorder, index + 1, end);
//     root->left = solve(inorder, postorder, start, index - 1);
//     return root;
// }
// TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
// {
//     return solve(inorder, postorder, 0, postorder.size() - 1);
// }
int main()
{

    return 0;
}