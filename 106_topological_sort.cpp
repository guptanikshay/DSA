#include <bits/stdc++.h>
using namespace std;

// DAG stands for Directed Acyclic Graph
// Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex 'u' to vertex 'v', u comes before v in the ordering. Topological Sorting for a Graph is not possible if the graph is not a DAG, because the cylcic order will contradict itself (for instance, if u and v are part of a cycle the u should come before v and v should come before u, which is not possilbe). TC=O(N+E), SC=O(N)

// TOPOLOGICAL SORT USING DFS
// Approach: We traverse the graph using dfs and while backtracking the recursive call, we put that particular node into a stack. After the dfs function executes entirely, we pop nodes from the stack and push them into our ans vector.
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, stack<int> &s)
{
    visited[node] = true;
    for (auto i : adjList[node])
    {
        if (!visited[i])
            dfs(i, visited, adjList, s);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<pair<int, int>> &edges, int N, int M)
{
    /*
       Write your code here
       Return any valid topolocial Sort
       Verdict: 'Valid' or 'Invalid'
    */
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < M; i++)
        adjList[edges[i].first].push_back(edges[i].second);
    unordered_map<int, bool> visited;
    vector<int> ans;
    stack<int> s;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList, s);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// NOTE:- Indegree of a vertex is defined as the no. of incoming edges on that vertex in a directed graph.

// TOPOLOGICAL SORT USING BFS (KAHN'S ALGORITHM)
// Approach: 1. Find the indegree of all the nodes   2. Push the nodes having indegree=0 into the queue, then pop the front node and insert it in the ans vector  3. Now do BFS of the graph and decrement the indegree of the all the neighbour nodes of the front node   4. Again push all the nodes with indegree=0 into the queue, then pop the front node and insert it in ans and decrement indegree of the neigbour nodes  5. Continue this process until a node with zero neighbours is encountered
// TC=O(N+E) SC=O(N+E)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(v);
    for (int i = 0; i < e; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto i : adjList[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return ans;
}

// CYCLE DETECTION IN DIRECTED GRAPHS USING BFS
// Approach: We use Kahn's algorithm to count the number of nodes in the topological sort, if they are equal to the number of elements in graph, then its valid topological sort and the graph does not have any cycle. If it is not equal to no. of elements, then its invalid TS and a cycle exits.
#include <bits/stdc++.h>
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(v);
    for (int i = 0; i < e; i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int front = q.front();
        cnt++;
        q.pop();
        for (auto i : adjList[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    if (cnt == v)
        return false;
    return true;
}
int main()
{

    return 0;
}