#include <bits/stdc++.h>
using namespace std;

// Kth LARGEST SUBARRAY SUM
// BRUTE FORCE: We find all the subarrays (by traversing the entire array ahead an element for every element) and calculate their sum (takes O(n^2)) and store them in a vector (whose length will be n^2, as there are total n^2 subarrays), and then we sort this vector in ascending order and return the Kth element from end, which is our ans. TC: O(N^2 log(N)) & SC: O(N^2)
// OPTIMAL: There is no scope of optimizing time, but we can optimize space by reducing it to O(K) and this can be done using a minHeap. First of all we create a minHeap, and after finding a subarray sum if the size of minHeap is less than K we simply insert it and if its greater than K we check whether this sum is larger than minHeap's top and if it is we insert it. In the end, minHeap's top is our answer.
int kthLargest(vector<int> &Arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            if (minH.size() < K)
                minH.push(sum);
            else if (minH.top() < sum)
            {
                minH.pop();
                minH.push(sum);
            }
        }
    }
    return minH.top();
}

// MERGE K SORTED ARRAYS: Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python)
// Approach 1:- The brute force method is create an answer array and insert all the elements of the given arrays in that array and sort the answer array. But, here TC=O(n*k log(n*k)) & SC=O(n*k) :(
// Approach 2:- The second approach is by using minHeap. All the first elements of the vectors are inserted in the heap along with their respective indexes and then the minimum element is inserted in the answer vector and then the next element (if exists) of that minimum vector (the vector whose element got popped out) is pushed into the heap. This process is continued until the minHeap is not empty. Here, TC=O(n*k log(k)) & SC=O(n*k)
class Node
{
public:
    int data;
    int i;
    int j;
    Node(int data, int i, int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    priority_queue<Node *, vector<Node *>, compare> minH;
    for (int i = 0; i < K; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        minH.push(temp);
    }
    vector<int> ans;
    while (!minH.empty())
    {
        Node *temp = minH.top();
        minH.pop();
        if (temp->j < K - 1)
        {
            Node *t = new Node(arr[temp->i][temp->j + 1], temp->i, temp->j + 1);
            minH.push(t);
        }
        ans.push_back(temp->data);
    }
    return ans;
}
// The same question can be framed for LinkedLists instead of arrays, but logic remains the same. Here, TC=O(n*k log(k)) & SC=O(1) :)
// class compare
// {
// public:
//     bool operator()(ListNode *a, ListNode *b)
//     {
//         return a->val > b->val;
//     }
// };
// ListNode *mergeKLists(vector<ListNode *> &lists)
// {
//     priority_queue<ListNode *, vector<ListNode *>, compare> minH;
//     int n = lists.size();
//     if (n == 0)
//         return NULL;
//     for (int i = 0; i < n; i++)
//     {
//         if (lists[i])
//             minH.push(lists[i]);
//     }
//     ListNode *ans = NULL;
//     ListNode *curr = ans;
//     while (!minH.empty())
//     {
//         ListNode *temp = minH.top();
//         minH.pop();
//         if (temp->next != NULL)
//             minH.push(temp->next);
//         if (!ans)
//         {
//             ans = temp;
//             curr = ans;
//         }
//         else
//         {
//             curr->next = temp;
//             curr = curr->next;
//         }
//     }
//     return ans;
// }
int main()
{

    return 0;
}