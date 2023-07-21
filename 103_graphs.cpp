// Graph is a type of data structure that consists of multiple nodes connected through edges. 
// TERMINOLOGIES:-
// Node: An entity to store data.
// Edge: To connect the nodes.
// Degree: No. of edges connected to that node.
// Path: A sequence of nodes that can be travelled and in which each node appears exactly once.
#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map <int, list<int>> adj;
    void addEdge(int u, int v, bool direction=0){
        // direction = 0 -> undirected
        // direction = 1 -> directed graph
        adj[u].push_back(v);
        if(!direction) adj[v].push_back(u);
    }
    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<"-> ";
            for(auto j: i.second) cout<<j<<", ";
            cout<<"\n";
        }
    }
};
int main(){
    int n, m;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;
    graph g;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v);
    }
    g.printAdjList();
    return 0;
}