#include <bits/stdc++.h>
using namespace std;

// SMALLEST RANGE COVERING ELEMENTS FROM K LISTS: You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
// Approach 1:- So we have K sorted lists of N size, i.e., we have matrix of N*K size. We make an array that stores the pointer to the first elements of all the lists and also keep track of the maxi and mini and range size, and apart from that we maintain ansMini and ansMaxi to stoe the values with minimum range. Now this maxi and mini from the first column gives us a valid answer, but we want the one with the smallest range, so to decrease the range we can either increase mini (by moving to the next element in that ) or decrease maxi. So we increase mini, update the pointer vector and calculate mini and maxi again, and if the range is smaller we update our answer. This process continues until one of the pointer reaches the end.
// Approach 2:- Here we create a minHeap and push all the first elements from the lists into it. While doing so, we also keep track of the maximum element, and after that loop we store current maximum and minimum (minHeap.top()) in final ansMax and ansMin, and store their difference as well. Then we pop the top element from the heap and insert the next element from the corresponding list and update our current maximum and minumum, and if their difference is less than our original diff, we update our ansMax ansMin, and we continue to do this until any of the list ends. Here, TC = O(n*k*log(k)), SC=O(k)
class Node
{
public:
    int data;
    int i;
    int j;
    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
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
vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<Node *, vector<Node *>, compare> minH;
    int mini = 100000, maxi = -100000, ansMin, ansMax;
    for (int i = 0; i < nums.size(); i++)
    {
        minH.push(new Node(nums[i][0], i, 0));
        maxi = max(maxi, nums[i][0]);
    }
    mini = ansMin = minH.top()->data;
    ansMax = maxi;
    int diff = maxi - mini;
    while (!minH.empty())
    {
        Node *temp = minH.top();
        minH.pop();
        if ((temp->j) < (nums[temp->i].size() - 1))
        {
            minH.push(new Node(nums[temp->i][temp->j + 1], temp->i, temp->j + 1));
            mini = minH.top()->data;
            maxi = max(maxi, nums[temp->i][temp->j + 1]);
            if (diff > maxi - mini)
            {
                ansMax = maxi;
                ansMin = mini;
                diff = ansMax - ansMin;
            }
        }
        else
            break;
    }
    vector<int> ans;
    ans.push_back(ansMin);
    ans.push_back(ansMax);
    return ans;
}

// FIND MEDIAN FROM DATA STREAM :- A stream of numbers is coming as input in any order. You are supposed to find the median of that stream at every step. We are supposed to implement the MedianFinder class that contains the functions balance, addNum, findMedian.
// Approach 1: As the integers we'll have at each step are not sorted, we can sort the integers received in the first step (O(n logn)) and find the median, and then insert the integer that we receive in every other step (O(n^2) in n steps) and then find the median. TC: O(n^2)
// Approach 2: We can use two heaps, a minHeap (for the elements greater than median) and a maxHeap (for elements smaller than median). We insert the upcoming element in the minHeap if it is greater than median and in maxHeap if it is smaller than median and then we balance the heaps. If heaps are of equal size, the median is average of both tops, else the median is the top of the heap of greater size.
priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
void balance()
{
    if (maxH.size() > minH.size() + 1)
    {
        minH.push(maxH.top());
        maxH.pop();
    }
    else if (minH.size() > maxH.size() + 1)
    {
        maxH.push(minH.top());
        minH.pop();
    }
}
void addNum(int num)
{
    if (!maxH.size() || num < maxH.top())
        maxH.push(num);
    else
        minH.push(num);
    balance();
}
double findMedian()
{
    if (minH.size() > maxH.size())
        return minH.top();
    if (maxH.size() > minH.size())
        return maxH.top();
    return (maxH.top() + minH.top()) / 2.0;
}

// REORGANIZE STRING: In this question we are given a string with some repetitive characters, and we are supposed to rearrange the characters (not to remove) and return a string with no adjacent character same (return empty string if not possible).
// Approach: The approach is to store the frequency count of every character and push this data into a maxHeap. Then pop twice from the heap and add these popped characters to the answer string. Push'em back if their frequecy is not zero yet. Finally, if there are any characters left in the heap with greater than one freq, return empty str, else return our ans.
// class Node
// {
// public:
//     char c;
//     int count;
//     Node(char ch, int n)
//     {
//         c = ch;
//         count = n;
//     }
// };
// class compare
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->count < b->count; // If the second element is given higher priority, its a maxHeap and if the first element is given priority its a minHeap. Basically if the function returns true, the new element (2nd one) stays at that level and if returns false it goes for comparision with next level.
//     }
// };
// string reorganizeString(string s)
// {
//     priority_queue<Node *, vector<Node *>, compare> maxH;
//     map<char, int> m;
//     for (int i = 0; i < s.size(); i++)
//         m[s[i]]++;
//     for (auto i : m)
//         maxH.push(new Node(i.first, i.second));
//     string ans = "";
//     while (maxH.size() > 1)
//     {
//         Node *one = maxH.top();
//         maxH.pop();
//         Node *two = maxH.top();
//         maxH.pop();
//         ans.push_back(one->c);
//         ans.push_back(two->c);
//         one->count--;
//         two->count--;
//         if (one->count)
//             maxH.push(one);
//         if (two->count)
//             maxH.push(two);
//     }
//     if (maxH.size())
//     {
//         Node *temp = maxH.top();
//         ans.push_back(temp->c);
//         if (temp->count > 1)
//             return "";
//     }
//     return ans;
// }
int main()
{

    return 0;
}