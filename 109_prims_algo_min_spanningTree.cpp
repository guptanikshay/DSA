#include <bits/stdc++.h>
using namespace std;

// SPANNING TREE:- When you convert a graph into a tree such that it contains n nodes and n-1 edges and every node is reachable through every other node.
// Find the minimum spanning tree using Prim's Algorithm for the given graph.
// Approach:- We need 3 arrays which are key[n], parent[n], mst[n] (n=> no. of nodes) and the adjacency list and initialize all their elements with INF, -1 and false respectively. Then we make the key[src]=0 and start algorithm which has the following steps:
// 1. Find the min element in the key array and store its index and the minimum value.
// 2. Make mst[index]=true and traverse the neighbours of that index
// 3. If mst[neighbour.node]=false and neighbour.weight<key[neighbour.node], update parent[neighbour.node]=index and key[neighbour.node]=neighbour.weight, and continue this loop for i=0 to i<n
// TC=O(N^2), but it can be optimized to O(N logN) using Heaps, SC=O(N)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < m; i++)
    {
        adjList[g[i].first.first].push_back(make_pair(g[i].first.second, g[i].second));
        adjList[g[i].first.second].push_back(make_pair(g[i].first.first, g[i].second));
    }
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    key[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int i = 1; i <= n; i++)
        {
            if (!mst[i] && key[i] < mini)
            {
                u = i;
                mini = key[i];
            }
        }
        mst[u] = true;
        for (auto i : adjList[u])
        {
            if (!mst[i.first] && i.second < key[i.first])
            {
                parent[i.first] = u;
                key[i.first] = i.second;
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {
        res.push_back({{parent[i], i}, key[i]});
    }
    return res;
}
int main()
{

    return 0;
}