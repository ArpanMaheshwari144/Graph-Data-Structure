// Detect cycle in a directed graph using DFS [https://bit.ly/3QwPVsi]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node])
    {
        // when the node is not visited
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis))
            {
                return true;
            }
        }
        // if the node is previously visited but it has to be visited on the same path
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0; // backtrack
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> adj[3];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);

    bool ans = isCyclic(3, adj);
    if (ans)
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "Cycle is not present";
    }

    return 0;
}