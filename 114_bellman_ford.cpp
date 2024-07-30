#include <bits/stdc++.h>
using namespace std;

// BELLMAN FORD ALGORITHM: This algo is used to find the shortest path between a source node and destination node and the graph may contain negatively weighted edges. We are studying this algo because Dijkstra's algo doesn't work on -ve edges.
// NOTE: For Bellman Ford algo to work, no negative cycle should be present in the graph. A negative cylce is the one in which the sum of all edges is negative. But BF algo can be used to check the presence of a negative cycle in a graph.
// To apply BF algo to an undirected graph, convert it into a directed graph first (the graph will contain edges in both directions {0 -> <- 1})
// TC=O(N*E)  SC=O(N)

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    // Run a loop n-1 times on each edge to check for the condition of shortest path
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
                dist[v] = dist[u] + wt;
        }
    }
    // To check for negative weight cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
            flag = 1;
    }
    if (!flag)
        return dist[dest];
    return -1;
}
int main()
{

    return 0;
}

// If graph can be colored with just two colors such that no two adjacent nodes have the same color, it is called a bipartite graph.
//  Linear graphs without any cycles and graphs with an even cycle length are always bipartite.
// Graphs with an odd cycle length are always bipartite.