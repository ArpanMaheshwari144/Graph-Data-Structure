// Prim's Algorithm using Brute Force => TC -> O(n^2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // declare the adjacent list
    vector<pair<int, int>> adj[n + 1];

    // take edges as input
    cout << "Enter the edges along with weight of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    // Prim's Algorithm begins from here
    int parent[n];
    int key[n];
    bool mst[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int mini = INT_MAX, u;

        // finding minimum in the key array
        for (int v = 0; v < n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}