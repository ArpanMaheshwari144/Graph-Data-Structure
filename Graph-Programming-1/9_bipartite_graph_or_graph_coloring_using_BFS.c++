/* Bipartite Graph -> that can be colored using exactly 2 colors such that no two adjacent nodes have same color */
#include <bits/stdc++.h>
using namespace std;

// in this we have 2 colors -> 0 and 1
bool bipartiteBFS(int source, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(source);
    color[source] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node]; // changing the color of the adjacent node
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
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

    if (checkBipartite(adj, n))
    {
        cout << "Yes, it is a Bipartite graph";
    }
    else
    {
        cout << "No, it is not a Bipartite graph";
    }

    return 0;
}