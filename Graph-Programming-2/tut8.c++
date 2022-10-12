// Detect a Cycle in an Undirected Graph using DFS [https://bit.ly/3cZMJXp]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;

    // visit adjacent nodes
    for (auto adjacentNode : adj[node])
    {
        // unvisited adjacent node
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adj) == true)
            {
                return true;
            }
        }
        // visited node but not a parent node
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};

    // for graph with connected components
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    bool ans = isCycle(5, adj);
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