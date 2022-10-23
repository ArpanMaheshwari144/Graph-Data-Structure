// Kruskal's Algorithm - Minimum Spanning Tree [https://bit.ly/3eLuYvH]

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        // resize means it will shrink according to the size, otherwise it will be the same size as we declared
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if (ultimateParentU == ultimateParentV)
        {
            return;
        }

        if (size[ultimateParentU] < size[ultimateParentV])
        {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        }
        else
        {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution
{
public:
    void addEdge(vector<vector<int>> adj[], int u, int v, int wt)
    {
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(wt);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(wt);
        adj[v].push_back(t2);
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};

int main()
{

    int V = 3;
    vector<vector<int>> adj[V];
    Solution obj;
    obj.addEdge(adj, 0, 1, 5);
    obj.addEdge(adj, 1, 2, 3);
    obj.addEdge(adj, 0, 2, 1);
    cout << obj.spanningTree(V, adj);

    return 0;
}