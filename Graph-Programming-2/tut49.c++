// Strongly Connected Components [https://bit.ly/3R6LzID]

/* Strongly Connected Components (Only Applicable for directed graphs) -> A directed graph is strongly connected if there is a path between all pairs of vertices. */

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adjT[])
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs2(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i); // reverse the graph
        }
    }

    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs2(node, vis, adjT);
        }
    }
    return scc;
}

int main()
{
    int V = 3;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);

    cout << "The number of strongly connected components are: " << kosaraju(V, adj) << "\n";

    return 0;
}
