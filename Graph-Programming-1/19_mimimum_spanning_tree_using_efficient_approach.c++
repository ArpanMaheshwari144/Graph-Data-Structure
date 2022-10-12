// Prim's Algorithm using Efficient Approach => TC -> O(n(logn))
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
    }

    // Declaration of MinHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0}); // pair = (key[i], i)

    for (int count = 0; count < n - 1; count++) // O(n)
    {
        // pq.top().second -> i which is index of the element
        int u = pq.top().second; // log(n)
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u]) // O(E) E -> Number of edges
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v])
            {
                parent[v] = u;
                pq.push({key[v], v}); // pair = (key[i], i)
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