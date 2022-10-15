// Eventual Safe States [https://bit.ly/3C90n59]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> adjRev[V];
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        // this means i -> it but we have to reverse the edges;
        for (auto it : adj[i])
        {
            adjRev[it].push_back(i); // it -> i
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main()
{
    vector<int> adj[7];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 0);
    addEdge(adj, 4, 5);

    vector<int> ans = eventualSafeNodes(7, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}