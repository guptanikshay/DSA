#include <bits/stdc++.h>
using namespace std;
// If a node, when removed, divides the graph into two or more separate components, is called an Articulation point.
// PS: FIND ALL THE ARTICULATION POINTS IN A GIVEN GRAPH (TARJANS ALGO)
// Approach:- 1. Create a parent var, time var and 2 arrays namely disc and low to store the discovery time and lowest possilbe time of nodes, and initialize with -1 (Visited map is not required as a node is considered unvisited if disc[node]==-1)    2. Create the adjacencyList   3. Call the dfs function for all the unvisited nodes, in which we traverse all the neighbours of this node and check if low[nbr]>=disc[node] && parent!=-1, if true, the node is added to result and if false, low[node] is upadated     4. At last the condition of parent = -1 is handled, if the node has two or more children, then it is an articulation point.
// TC=O(N+E)    SC=O(N)
void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, list<int>> &adjList, vector<int> &ap, int &time)
{
    disc[node] = low[node] = time++;
    int child = 0;
    for (auto nbr : adjList[node])
    {
        if (nbr == parent)
            continue;
        if (disc[nbr] == -1)
        {
            dfs(nbr, node, disc, low, adjList, ap, time);
            low[node] = min(low[node], low[nbr]);
            if (low[nbr] >= disc[node] && parent != -1)
                ap[node] = true;
            child++;
        }
        else
            low[node] = min(low[node], disc[nbr]);
    }
    if (parent == -1 && child > 1)
        ap[node] = 1;
}
int main()
{
    int n = 5, e = 4;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }
    int time = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
            dfs(i, -1, disc, low, adjList, ap, time);
    }
    cout << "Articulation Points are: ";
    for (int i = 0; i < n; i++)
    {
        if (ap[i])
            cout << i << " ";
    }
    return 0;
}