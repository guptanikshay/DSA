#include <bits/stdc++.h>
using namespace std;

// DISJOINT SET DATA STRUCTURE (PreRequisite)
// Two sets are called disjiont if they don't have any element in common.
// A disjoint set data structure is the one that stores disjoint subset of elements. It supports operations like adding elements to a disjoint set, merging 2 disjoint sets using Union operation and finding the parent/representative of a disjoint set.

// PS: FIND THE MINIMUM SPANNING TREE OF A GIVEN GRAPH USING KRUSKAL'S ALGORITHM
// Approach:- 1. Create arrays parent and rank of nodes and initialize them using makeSet operation. Initially, the parent of node will be the node itself and rank of all nodes will be 0    2. The union set operation finds the parents of both input nodes and if the rank of parents are same, any node is made the new parent of the other node and the rank this parent node is incremented, else if the ranks are different, one with the higher rank is made the parent and no ranks are incremented    3. To find the weight of the MST, we find the parents of the input nodes and if they are different (i.e., belong to different disjoint sets) we merge them using the UnionSet operation and add the weight of this edge to our ans and return the ans in final step
// TC=O(N logN)    SC=O(N)
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minW = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v)
        {
            minW += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minW;
}
int main()
{

    return 0;
}