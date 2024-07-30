#include <bits/stdc++.h>
using namespace std;

// It is used to calculate the minimum distance of a node from all the nodes. The approach used here is  different from the one used in shortest path through BFS.
// Approach:- 1. Create the adjacency list   2. Make a set/priority queue to store the nodes with their distances from the source node and to pop the node with minimum distance whenever we need one (set also has the heap property)   3. Make a distance array that stores the distance of each node from the source node and initialize its each value with INF   4. Make dist[src]=0 and insert the pair (0, 0) <node, dist> into the set    5. Pop the node from the set and check if the distance of all nodes connected to this node (adj List) is smaller than the node stored in the dist array, using this eqn:- { dist[top.second] + adjList[node.second] < dist[top.first] }   6. If it is true, update the dist array and insert new pair of <node, dist> in the set and continue this operation until the set becomes empty.
// TC=O(E logV)  SC=O(N+E)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.
    // Create Adjacency List
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        adjList[vec[i][0]].push_back(make_pair(vec[i][1], vec[i][2]));
        adjList[vec[i][1]].push_back(make_pair(vec[i][0], vec[i][2]));
    }
    // Make the set to store the nodes and distances
    set<pair<int, int>> st; /* <node, dist> */
    // Make the distance array
    vector<int> dist(vertices);
    // Initialize the dist array with infinity
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;
    dist[source] = 0; // Distance of source node is 0
    st.insert(make_pair(source, 0));
    while (!st.empty())
    {
        pair<int, int> top = *(st.begin());
        st.erase(st.begin());
        // Traverse the neighbours
        for (auto i : adjList[top.first])
        {
            if ((top.second + i.second) < dist[i.first])
            {
                // Delete the pair if already present in the set
                auto record = st.find(make_pair(i.first, dist[i.first]));
                if (record != st.end())
                    st.erase(record);
                // Update the dist array
                dist[i.first] = top.second + i.second;
                // Insert the new mapping into the set
                st.insert(make_pair(i.first, dist[i.first]));
            }
        }
    }
    return dist;
}
int main()
{

    return 0;
}