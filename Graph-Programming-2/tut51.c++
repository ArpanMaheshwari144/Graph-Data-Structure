#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int timeOfInsertion[], int lowestTimeOfInsertion[], vector<int> &mark)
{
    vis[node] = 1;
    timeOfInsertion[node] = lowestTimeOfInsertion[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
        {
            continue;
        }

        if (vis[it] == 0)
        {
            dfs(it, node, vis, adj, timeOfInsertion, lowestTimeOfInsertion, mark);
            lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], lowestTimeOfInsertion[it]);
            if (lowestTimeOfInsertion[it] >= timeOfInsertion[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], timeOfInsertion[it]);
        }
    }

    if (child > 1 && parent == -1)
    {
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    int timeOfInsertion[n];
    int lowestTimeOfInsertion[n];
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, adj, timeOfInsertion, lowestTimeOfInsertion, mark);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
        {
            ans.push_back(i);
        }
    }

    if (ans.size() == 0)
    {
        return {-1};
    }
    return ans;
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 4, 3);
    addEdge(adj, 2, 3);

    vector<int> ans = articulationPoints(V, adj);
    cout << "Articulation points are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}