#include <bits/stdc++.h>
using namespace std;

// In a greedy algorithm, we choose the most optimal solution at that particular moment, it may or may not be the most optimal solution for the entire problem

// N MEETINGS IN ONE ROOM: There is one meeting room in a firm. There are n meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i. What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time ? Return the maximum number of meetings that can be held in the meeting room. Start time of one chosen meeting cannot be equal to the end time of other chosen meeting.
// APPROACH: We sort all the meetings based on their end time, then we pick the feasible meetings in that order.
// static bool cmp(pair<int, int> &a, pair<int, int> &b)
// {
//     return a.second < b.second;
// }
// int maxMeetings(int start[], int end[], int n)
// {
//     // Your code here
//     vector<pair<int, int>> meets;
//     for (int i = 0; i < n; i++)
//         meets.push_back(make_pair(start[i], end[i]));
//     sort(meets.begin(), meets.end(), cmp);
//     int count = 1, ansEnd = meets[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         if (meets[i].first > ansEnd)
//         {
//             count++;
//             ansEnd = meets[i].second;
//         }
//     }
//     return count;
// }

// MAXIMUM MEETINGS IN ONE ROOM: Same question as above, only catch is that you need to print the feasible meetings.
// static bool cmp(pair<int, int> &a, pair<int, int> &b)
// {
//     return a.second < b.second;
// }
// vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
// {
//     vector<pair<int, int>> meets;
//     map<pair<int, int>, int> index;
//     for (int i = 0; i < N; i++)
//     {
//         meets.push_back(make_pair(S[i], F[i]));
//         if (index[{S[i], F[i]}] == 0)
//             index[{S[i], F[i]}] = i;
//     }
//     sort(meets.begin(), meets.end(), cmp);
//     vector<int> ans;
//     ans.push_back(index[{meets[0].first, meets[0].second}] + 1);
//     int ansEnd = meets[0].second;
//     for (int i = 1; i < N; i++)
//     {
//         if (meets[i].first > ansEnd)
//         {
//             ansEnd = meets[i].second;
//             ans.push_back(index[{meets[i].first, meets[i].second}] + 1);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
// }

// HUFFMAN ENCODING: We are given a string s along with a freq array f[] which stores the frequency of i'th character in some other original string, i.e., s[i] has frequency equal to f[i] in that original string. We need to print the Huffman encoding of every character in s. Huffman encoding is found using the Huffman tree where '0' represents going left in the tree and '1' represents going right. The Huffman tree has leaf node values equal to frequency of characters in s and the parent node is found by summing the value at right and left node. So basically we need to find the path to reach every character's frequency in the Huffman tree.
// APPROACH: We make nodes using all the frequencies and push them into a minHeap. Then we pop two nodes from the minHeap and create a new Node which has its left and right as these nodes and its value equal to the sum of the values of these nodes, and then we push it back into the minHeap. We continue this until we are left with one node in the heap, which are our root node of the Huffman tree. Then we simply perform a pre-order traversal on the tree and store the paths to leaf nodes.
// class Node
// {
// public:
//     int data;
//     Node *left, *right;
//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// class cmp
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->data > b->data;
//     }
// };
// class Solution
// {
// public:
//     void traverse(Node *root, vector<string> &ans, string temp)
//     {
//         if (root->left == NULL && root->right == NULL)
//         {
//             ans.push_back(temp);
//             return;
//         }
//         traverse(root->left, ans, temp + '0');
//         traverse(root->right, ans, temp + '1');
//     }
//     vector<string> huffmanCodes(string S, vector<int> f, int N)
//     {
//         // Code here
//         priority_queue<Node *, vector<Node *>, cmp> minHeap;
//         for (int i = 0; i < N; i++)
//         {
//             Node *temp = new Node(f[i]);
//             minHeap.push(temp);
//         }
//         while (minHeap.size() > 1)
//         {
//             Node *left = minHeap.top();
//             minHeap.pop();
//             Node *right = minHeap.top();
//             minHeap.pop();
//             Node *temp = new Node(left->data + right->data);
//             temp->left = left;
//             temp->right = right;
//             minHeap.push(temp);
//         }
//         Node *root = minHeap.top();
//         vector<string> ans;
//         string temp = "";
//         traverse(root, ans, temp);
//         return ans;
//     }
// };

// FRACTIONAL KNAPSACK: Just like in 0/1 Knapsack, we have a knapsack with a capacity and items with their weights and values and we need to put the maximum value into our knapsack, only catch is that we can pick fractional amount of items, i.e., if the weight is 30 kg and we have only 20kg capacity left, so we can pick 20kg of that item.
// APPROACH: We sort the items on according to their value per unit weight and start by putting the max val/wt into our knapsack. When we reach a point that we can't keep the entire amount into our knapsack, we put a fraction of that.
struct Item
{
    int value;
    int weight;
};
static bool cmp(pair<double, Item> &a, pair<double, Item> &b)
{
    return a.first > b.first;
}
double fractionalKnapsack(int w, Item arr[], int n)
{
    // Your code here
    vector<pair<double, Item>> v;
    for (int i = 0; i < n; i++)
    {
        double val = (1.0 * arr[i].value) / arr[i].weight;
        v.push_back({val, arr[i]});
    }
    sort(v.begin(), v.end(), cmp);
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if (w < v[i].second.weight)
        {
            total += (w * 1.0) * v[i].first;
            w = 0;
        }
        else
        {
            total += v[i].second.value;
            w -= v[i].second.weight;
        }
        if (!w)
            break;
    }
    return total;
}
int main()
{

    return 0;
}