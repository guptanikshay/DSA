#include <bits/stdc++.h>
using namespace std;

// STRONGLY CONNECTED GRAPH: A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of the graphs are subgraphs which are themselves strongly connected.
// Kosaraju's Algorithm is used to find all the strongly connected components present in a graph. It consists of 3 steps-    1. Sort all nodes on the basis of their finishing time (Topological Sort)           2. Transpose Graph     3. DFS (count and print SCC's)
// TC=O(N+E)  SC=O(N)

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
            dfs(nbr, vis, s, adj);
    }
    s.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;
    for (auto nbr : transpose[node])
    {
        if (!vis[nbr])
            revDfs(nbr, vis, transpose);
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Create adjacencyList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
        adjList[edges[i][0]].push_back(edges[i][1]);
    // Find the topological sort ordering of the graph
    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, s, adjList);
    }
    // Create transpose of the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto nbr : adjList[i])
            transpose[nbr].push_back(i);
    }
    // Count the number of SCC's using this ordering
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}
int main()
{

    return 0;
}