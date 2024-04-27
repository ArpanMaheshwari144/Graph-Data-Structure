// Detect a Cycle in Directed Graph using Kahn's Algorithm [https://bit.ly/3QwPVsi]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool isCyclic(int V, vector<int> adj[])
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

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

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

    // If the topo sort traverses all the edges in the graph this means there is no cycle
    if (count == V)
    {
        // if toposort array size == number of elements in the graph then it is a DAG
        return false;
    }

    // If the topo sort did not traverses all the edges in the graph this means there is a cycle
    return true;
}

int main()
{
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    bool ans = isCyclic(4, adj);
    if (ans)
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "Cycle is not present";
    }
}
