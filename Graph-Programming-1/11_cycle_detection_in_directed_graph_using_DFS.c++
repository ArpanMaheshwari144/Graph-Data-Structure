#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, adj, vis, dfsVis))
            {
                return true;
            }
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    int vis[n], dfsVis[n];
    memset(vis, 0, sizeof(vis));
    memset(dfsVis, 0, sizeof(dfsVis));

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsVis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // declare the adjacent list
    vector<int> adj[n + 1];

    // take edges as input
    cout << "Enter the edges of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isCycle(n, adj))
    {
        cout << "Yes, it is a cyclic graph";
    }
    else
    {
        cout << "No, it is not a cyclic graph";
    }

    return 0;
}