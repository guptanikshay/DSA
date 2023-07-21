#include <bits/stdc++.h> 
using namespace std;

// PS: Print BFS of an undirected and disconnected graph. Breadth First Search Traversal of a graph is an algorithm used to visit all the nodes in a graph. In this algo, one node is selected and then all the nodes connected to it are visited one by one. A graph is disconnected if at least two nodes are not connected by a path.
void createAdjList(vector<pair<int,int>> &edges, unordered_map <int, set<int>> &adjList){
    for(auto i: edges){
        adjList[i.first].insert(i.second);
        adjList[i.second].insert(i.first);
    }
}
void bfs(unordered_map <int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int i){
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        ans.push_back(fr);
        for(auto j: adjList[fr]){
            if(!visited[j]){
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map <int, set<int>> adjList;
    vector<int> ans;
    unordered_map <int, bool> visited;

    createAdjList(edges, adjList);
    for(int i=0; i<vertex; i++){
        if(!visited[i]) bfs(adjList, visited, ans, i);
    }
    return ans;
}

// DFS:- In this traversal, we visit the first node and then visit the next node connected and then the next node connected to this node (unlike BFS in which we visit all the adjacent nodes of a single node first).
void dfs(int i, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &row){
    row.push_back(i);
    visited[i] = true;
    for(auto j: adjList[i]){
        if(!visited[j])
        dfs(j, adjList, visited, row); 
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    for(int i=0; i<edges.size(); i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> row;
            dfs(i, adjList, visited, row);
            ans.push_back(row);
        }
    }
    return ans;
}
int main(){
    
    return 0;
}