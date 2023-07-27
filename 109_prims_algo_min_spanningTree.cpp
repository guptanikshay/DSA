#include <bits/stdc++.h>
using namespace std;

// SPANNING TREE:- When you convert a graph into a tree such that it contains n nodes and n-1 edges and every node is reachable through every other node.
// Find the minimum spanning tree using Prim's Algorithm for the given graph.
// Approach:- We need 3 arrays which are key[], parent[], mst[] and the adjacency list and initialize them as per requirement
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