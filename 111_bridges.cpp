#include <bits/stdc++.h>
using namespace std;
// A bridge in any graph is an edge, which when removed makes the graph disconnected, or more precisely increases the number of connected components in the graph.
// PS:- FIND ALL THE BRIDGES IN A GIVEN GRAPH
// Approach: We maintain a parent variable, a time varible and two arrays, discovery(n) and lowest(n) to store the discovery time and lowest possible time of discovery of node and we keep updating them during dfs. If at any point the low[nbr]>disc[i], then it is a bridge and gets pushed into the answer. Here nbr=>neighbour of node 'i', and 'i' is the node passed into the adjList
// TC=O(N+E)  SC=O(N)
void dfs(int i, int parent, int &time, vector<int> &disc, vector<int> &low, vector<vector<int>> &ans, unordered_map<int, list<int>> &adjList)
{
    disc[i] = low[i] = time++;
    for (auto nbr : adjList[i])
    {
        if (nbr == parent) // To avoid infinite loop
            continue;
        if (disc[nbr] == -1) // This implies that node is unvisited
        {
            dfs(nbr, i, time, disc, low, ans, adjList);
            low[i] = min(low[i], low[nbr]);
            if (low[nbr] > disc[i]) // To check bridge
            {
                vector<int> res;
                res.push_back(i);
                res.push_back(nbr);
                ans.push_back(res);
            }
        }
        else // Back edge ,when the node is already visited
            low[i] = min(low[i], disc[nbr]);
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < connections.size(); i++)
    {
        adjList[connections[i][0]].push_back(connections[i][1]);
        adjList[connections[i][1]].push_back(connections[i][0]);
    }
    int time = 0;
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
            dfs(i, parent, time, disc, low, ans, adjList);
    }
    return ans;
}
int main()
{

    return 0;
}