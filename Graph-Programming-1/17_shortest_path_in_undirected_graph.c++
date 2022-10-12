#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // declare the adjacent list
    vector<pair<int, int>> adj[n + 1]; // 1 based indexing in adjacency list

    // take edges as input
    cout << "Enter the edges along with weight of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    int source;
    cout << "Enter souce for graph: ";
    cin >> source;

    // Dijkstra's Algorithm begins from here
    // Dijkstra's Algorithm -> It means source to destination shortest path
    // Declaration of MinHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair => (distance, from)

    // 1 based indexing for calculating shortest path
    vector<int> distanceTo(n + 1, INT_MAX);

    distanceTo[source] = 0;
    pq.push(make_pair(0, source)); // (distance, from)

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (auto it : adj[prev]) // or for (it = adj[prev].begin(); it != adj[prev].end(); it++){}
        {
            int next = it.first;
            int nextDistance = it.second;
            if (distanceTo[next] > distance + nextDistance)
            {
                distanceTo[next] = distanceTo[prev] + nextDistance;
                pq.push(make_pair(distanceTo[next], next));
            }
        }
    }

    cout << "Shortest Path for every node from " << source << "(source)"
         << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << distanceTo[i] << " ";
    }

    return 0;
}