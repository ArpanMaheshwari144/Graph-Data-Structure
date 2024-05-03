// Prim's Algorithm - Minimum Spanning Tree [https://bit.ly/3ABwwRP]
/*
Spanning Tree:- A tree in which we have N nodes and N-1 edges and all nodes are reachable from each other.
Minimum Spanning Tree:- A tree in which we have N nodes and N-1 edges and all nodes are reachable from each other and if we do the sum of its weight it will give a minimum sum.
*/
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> adj[], int u, int v, int wt)
{
    vector<int> t1, t2;
    t1.push_back(v);
    t1.push_back(wt);
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(wt);
    adj[v].push_back(t2);
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0}); // (weight, node)
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int wt = it.first;
        pq.pop();

        if (vis[node] == 1)
        {
            continue;
        }

        // added to the MST
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if (!vis[adjNode])
            {
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    return sum;
}

int main()
{
    int V = 3;
    vector<vector<int>> adj[V];
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 0, 2, 1);
    cout << spanningTree(V, adj);

    return 0;
}
