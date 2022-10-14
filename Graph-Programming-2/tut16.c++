// Eventual Safe States [https://bit.ly/3C90n59]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    // traverse for adjacent nodes
    for (auto it : adj[node])
    {
        // when the node is not visited
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis, check))
            {
                check[node] = 0;
                return true;
            }
        }
        // if the node is previously visited but it has to be visited on the same path
        else if (pathVis[it])
        {
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0; // backtrack
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> safeNodes;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, pathVis, check);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
        {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}

int main()
{
    vector<int> adj[7];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 0);
    addEdge(adj, 4, 5);

    vector<int> ans = eventualSafeNodes(7, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}