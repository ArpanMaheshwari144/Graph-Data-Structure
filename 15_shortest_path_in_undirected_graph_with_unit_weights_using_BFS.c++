#include <bits/stdc++.h>
using namespace std;

void shortestPath(int source, int n, vector<pair<int, int>> adj[])
{
    int distance[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }

    queue<int> q;
    distance[source] = 0;
    q.push(source);

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (distance[node] + 1 < distance[it.first])
            {
                distance[it.first] = distance[node] + 1;
                q.push(it.first);
            }
        }
    }

    cout << "Shortest Path for every node from 0(source): ";
    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
}

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
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    shortestPath(0, n, adj);

    return 0;
}