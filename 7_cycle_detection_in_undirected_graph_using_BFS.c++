#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int n, vector<int> adj[], vector<int> &visited)
{
    // Create a queue for BFS
    queue<pair<int, int>> q;

    visited[s] = true;
    q.push({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // traversing all the adjacent nodes
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if (parent != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, n, adj, vis))
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
        adj[v].push_back(u);
    }

    bool ans = isCycle(n, adj);

    if (ans)
    {
        cout << "Cycle is detected";
    }
    else
    {

        cout << "Cycle is not detected";
    }

    return 0;
}