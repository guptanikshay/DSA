#include <bits/stdc++.h>
using namespace std;

// SHORTEST PATH IN UNDIRECTED GRAPHS: Given a source node and terminal node, find the shortest path between them.
// Approach:-  1. Create adjacency list   2. Make visited and parent maps and put inputs into them using bfs   3. Grab the terminal node and traverse back towards the source node and count the number of nodes in that path and this count will be the ans
// TC=O(N+E)   SC=O(N+E)
// vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
// {

//     // Write your code here
//     unordered_map<int, list<int>> adjList;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         adjList[edges[i].first].push_back(edges[i].second);
//         adjList[edges[i].second].push_back(edges[i].first);
//     }
//     unordered_map<int, bool> visited;
//     unordered_map<int, int> parent;
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     parent[s] = -1;
//     while (!q.empty())
//     {
//         int front = q.front();
//         q.pop();
//         for (auto i : adjList[front])
//         {
//             if (!visited[i])
//             {
//                 visited[i] = true;
//                 parent[i] = front;
//                 q.push(i);
//             }
//         }
//     }
//     vector<int> ans;
//     int curr = t;
//     ans.push_back(curr);
//     while (curr != s)
//     {
//         curr = parent[curr];
//         ans.push_back(curr);
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

// SHORTEST PATH IN DIRECTED ACYCLIC GRAPH
// TC=O(N+E)  SC=O(N+E)
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }
    void printAdj()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << ", " << j.second << "}, ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo)
    {
        vis[node] = true;
        for (auto neighbour : adjList[node])
        {
            if (!vis[node])
            {
                dfs(neighbour.first, vis, topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &topo)
    {
        dist[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto i : adjList[top])
                {
                    if ((dist[top] + i.second) < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    // Topological Sort
    unordered_map<int, bool> visited;
    stack<int> s;
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }
    int src = 1;
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    g.getShortestPath(src, dist, s);
    cout << "answer is\n";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}