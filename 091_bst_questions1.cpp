#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// CHECK WHETHER THE GIVEN TREE IS A VALID BST OR NOT
// Approach 1: Recursive with TC: O(N) and SC: O(N)
bool solve(Node *root, long long int min, long long int max)
{
    if (!root)
        return true;
    if (root->data <= min || root->data >= max)
        return false;
    else
        return (solve(root->left, min, root->data) && solve(root->right, root->data, max));
}
bool isValidBST(Node *root)
{
    long long int min = LLONG_MIN, max = LLONG_MAX;
    return solve(root, min, max);
}
// Approach 2: Using inorder traversal, TC: O(n), SC: O(n)
// void inorder(Node *root, vector<int> &inO)
// {
//     if (root == NULL)
//         return;
//     inorder(root->left, inO);
//     inO.push_back(root->data);
//     inorder(root->right, inO);
// }
// bool isValidBST(Node *root)
// {
//     if (!root)
//         return false;
//     vector<int> inO;
//     inorder(root, inO);
//     for (int i = 0; i < inO.size() - 1; i++)
//     {
//         if (inO[i] >= inO[i + 1])
//             return false;
//     }
//     return true;
// }

// Kth SMALLEST ELEMENT IN BST
// Approach 1: Using inorder traversal
void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
int kthSmallest(Node *root, int k)
{
    vector<int> in;
    inorder(root, in);
    return in[k - 1];
}
// Another recursive approach using a counter
// void solve(TreeNode *root, int &i, int k, int &ans)
// {
//     if (!root)
//         return;
//     solve(root->left, i, k, ans);
//     i++;
//     if (i == k)
//         ans = root->val;
//     solve(root->right, i, k, ans);
// }
// int kthSmallest(TreeNode *root, int k)
// {
//     int i = 0, ans = -1;
//     solve(root, i, k, ans);
//     return ans;
// }
// Approach 3: Using morrisInorder, that uses constant space
// void mInorder(TreeNode *root, int &i, int k, int &ans)
// {
//     TreeNode *curr = root, *temp;
//     while (curr != NULL && i != k)
//     {
//         if (!curr->left)
//         {
//             i++;
//             if (i == k)
//                 ans = curr->val;
//             curr = curr->right;
//         }
//         else
//         {
//             temp = curr->left;
//             while (temp->right != NULL && temp->right != curr)
//                 temp = temp->right;
//             if (temp->right == curr)
//             {
//                 temp->right = NULL;
//                 i++;
//                 if (i == k)
//                     ans = curr->val;
//                 curr = curr->right;
//             }
//             else
//             {
//                 temp->right = curr;
//                 curr = curr->left;
//             }
//         }
//     }
// }
// int kthSmallest(TreeNode *root, int k)
// {
//     int i = 0, ans = -1;
//     mInorder(root, i, k, ans);
//     return ans;
// }

// CODE TO FIND THE INORDER PREDECESSOR AND SUCCESSOR OF THE GIVEN KEY IN A BST
// pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
// {
//     // Write your code here.
//     int pre = -1;
//     int suc = -1;
//     BinaryTreeNode<int>* temp = root;
//     while(temp->data!=key){
//         if(temp->data>key){
//             suc = temp->data;
//             temp = temp->left;
//         }
//         else{
//             pre = temp->data;
//             temp = temp->right;
//         }
//     }
//     BinaryTreeNode<int> * leftT = temp->left;
//     BinaryTreeNode<int> * rightT = temp->right;
//     while(leftT!=NULL){
//         pre = leftT->data;
//         leftT = leftT->right;
//     }
//     while(rightT!=NULL){
//         suc = rightT->data;
//         rightT = rightT->left;
//     }
//     return {pre, suc}; //Another way to return a pair
// }

// CODE TO FIND THE LOWEST COMMON ANCESTOR OF TWO NODES IN A BST
// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     if ((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val))
//         return root;
//     else if (root->val >= p->val && root->val >= q->val)
//         return lowestCommonAncestor(root->left, p, q);
//     else
//         return lowestCommonAncestor(root->right, p, q);
// }
int main()
{

    return 0;
}