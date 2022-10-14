// Topological sort using DFS [https://bit.ly/3PvBfsm]

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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