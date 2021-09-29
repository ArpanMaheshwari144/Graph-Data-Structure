#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int source, int n, vector<pair<int, int>> adj[])
{
    int visited[n] = {0};
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            findTopoSort(i, visited, st, adj);
        }
    }

    int distance[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // if the node has been reached previously
        if (distance[node] != INF)
        {
            for (auto it : adj[node])
            {
                // it.second = edge weight
                if (distance[node] + it.second < distance[it.first])
                {
                    distance[it.first] = distance[node] + it.second;
                }
            }
        }
    }

    cout << "Shortest Path for every node from 0(source): ";
    for (int i = 0; i < n; i++)
    {
        if (distance[i] == 1e9)
        {
            cout << "INF";
        }
        else
        {
            cout << distance[i] << " ";
        }
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
    }

    shortestPath(0, n, adj);

    return 0;
}