// Topological sort using BFS or Kahn's Algorithm [https://bit.ly/3PvBfsm]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // node is in your topo sort so please remove it from indegree
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{
    vector<int> adj[6];
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);

    vector<int> ans = topoSort(6, adj);

    cout << "Valid Topo Sort: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}