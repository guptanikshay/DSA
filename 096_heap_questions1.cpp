#include <iostream>
#include <queue>
using namespace std;

// Kth SMALLEST ELEMENT IN AN UNSORTED ARRAY
// Approach 1: Sort the array and return ans. TC is O(NlogN)
// Approach 2: Using Heap -> In this approach we create a minHeap using first k elements and then we push the rest n-k elements if the element is smaller than the top element of the heap. At last, the heap will contain first K smallest element and the top element will be our ans.
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

// IS THE GIVEN BINARY TREE A HEAP
// void nodeCount(struct Node *root, int &count)
// {
//     if (!root)
//         return;
//     count++;
//     nodeCount(root->left, count);
//     nodeCount(root->right, count);
// }
// bool isCBT(struct Node *root, int i, int n) // n=>count
// {
//     if (!root)
//         return true;
//     if (i >= n)
//         return false;
//     return (isCBT(root->left, 2 * i + 1, n) && isCBT(root->right, 2 * i + 2, n));
// }
// bool isMaxOrder(struct Node *root) // This function checks the maxHeap property, i.e., whether the given tree is a maxHeap or not
// {
//     if (!root || (!root->left && !root->right))
//         return true;
//     if (!root->right)
//         return (root->data > root->left->data); // Here we don't need to check for subtree under this left node as we know that it is a complete binary tree, so if there will be more nodes a right node will exist.
//     return (root->data > root->left->data && root->data > root->right->data && isMaxOrder(root->right) && isMaxOrder(root->left));
// }
// bool isHeap(struct Node *tree)
// {
//     // code here
//     int count = 0, i = 0;
//     nodeCount(tree, count);
//     return (isCBT(tree, i, count) && isMaxOrder(tree));
// }

// MERGE TWO MAXHEAPS
// The appraoch is to merge the given arrays to form a single array in any order and then heapify this array and return the final array as answer.

// MINIMUM COST OF ROPES: Given an array containing the length of ropes, you are supposed to find the minimum total cost connecting all these ropes. Cost of connecting two ropes is equal to sum of their lengths. The total cost will vary depending on the order of ropes joined together.
// Approach: We basically need to pick the two smallest elements from the array and join them, so we'll use a minHeap and this question will get solved in a straight forward manner.
// long long minCost(long long arr[], long long n)
// {
//     // Your code here
//     if (n == 1)
//         return 0;
//     long long ans = 0, twosum = 0;
//     priority_queue<long long, vector<long long>, greater<long long>> pq;
//     for (long long i = 0; i < n; i++)
//         pq.push(arr[i]);
//     while (pq.size() > 1)
//     {
//         twosum = 0;
//         twosum += pq.top();
//         pq.pop();
//         twosum += pq.top();
//         pq.pop();
//         ans += twosum;
//         pq.push(twosum);
//     }
//     return ans;
// }

// CONVERT A COMPLETE BST TO A MIN HEAP
// The approach is to find the inorder of the given complete BST (which will be in ascending order) and to populate this BST in terms of preorder.
// void inorder(BinaryTreeNode *&root, queue<int> &in)
// {
//     if (!root)
//         return;
//     inorder(root->left, in);
//     in.push(root->data);
//     inorder(root->right, in);
// }

// void inToPre(BinaryTreeNode *&root, queue<int> &in)
// {
//     if (!root)
//         return;
//     root->data = in.front();
//     in.pop();
//     inToPre(root->left, in);
//     inToPre(root->right, in);
// }
// BinaryTreeNode *convertBST(BinaryTreeNode *root)
// {
//     // Write your code here.
//     queue<int> in;
//     inorder(root, in);
//     inToPre(root, in);
//     return root;
// }
int main()
{

    return 0;
}