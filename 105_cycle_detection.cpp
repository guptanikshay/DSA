#include <bits/stdc++.h>
using namespace std;
// CYLCE DETECTION IN UNDIRECTED GRAPHS
// Approach 1 (Using BFS): First of all we create the adjacency list using the edges vector and we keep track of all the visited nodes using the visited map. Call the function bfs for all the non visited nodes. Push the node in the queue, make its visited true, and keep track of its parent using the parent map. Now we traverse every node by pushing and popping from the queue and check whether its visited and its parent is not the last popped node and if thats true then a cycle is present as we are visiting the same node again while traversing. If the node is unvisited, we update the parent map and visited map and push it into the queue. TC=O(N+E), N=>no. of nodes, E=>no. of edges
bool isCyclicBFS(int node, unordered_map<int, bool> visited, unordered_map<int, list<int>> adjList)
{
    unordered_map<int, int> parent;
    visited[node] = true;
    parent[node] = -1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (auto i : adjList[fr])
        {
            if (visited[i] && i != parent[fr])
                return true;
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = fr;
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < n; i++) // For loop used as diconnected components might be present.
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adjList);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}

// Approach 2 (Using DFS): Here we travel one node after the other and if we reach a node which is already visited or its parent node is different than the one we saved in parent variable, a cycle is present, else a cycle is not present. TC=O(N+E), N=>no. of nodes, E=>no. of edges
bool isCyclicDFS(int node, int parent, unordered_map<int, bool> visited, unordered_map<int, list<int>> adjList)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);
            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < n; i++) // For loop used as diconnected components might be present.
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}

// CYCLE DETECTION IN DIRECTED GRAPHS
// Approach (Using DFS): The approach is mostly same as for undirected graphs. The change is that we use a new data structure dfsVisited to keep track of the nodes that are visited in the dfs traversal in one go. We make dfsVisited[node]=true when we enter the recursive call and make if false as we backtrack it. TC=O(N+E)
bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            bool hasCycle = isCyclicDFS(i, visited, dfsVisited, adjList);
            if (hasCycle)
                return true;
        }
        else if (dfsVisited[i])
            return true;
    }
    dfsVisited[node] = false;
    return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
        adjList[edges[i][0]].push_back(edges[i][1]);
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, visited, dfsVisited, adjList);
            if (ans)
                return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}