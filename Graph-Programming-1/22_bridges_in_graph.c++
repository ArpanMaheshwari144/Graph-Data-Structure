/* Bridges in Graph -> It is a edge on whose removal the graph is broken down into two or more number of component.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &insertionTime, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    insertionTime[node] = low[node] = timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
        {
            continue;
        }
        if (!vis[it])
        {
            dfs(it, node, vis, insertionTime, low, timer, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] > insertionTime[node])
            {
                cout << node << " " << it << endl;
            }
        }
        else
        {
            low[node] = min(low[node], insertionTime[it]);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    // take edges as input
    cout << "Enter the edges of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bcoz graph start from node 1
    vector<int> insertionTime(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> vis(n + 1, 0);
    int timer = 0;
    cout << "\nBridges in graph are\n";
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, insertionTime, low, timer, adj);
        }
    }

    // bcoz graph start from node 0
    // vector<int> insertionTime(n, -1);
    // vector<int> low(n, -1);
    // vector<int> vis(n, 0);
    // int timer = 0;
    // cout << "\nBridges in graph are\n";
    // for (int i = 0; i < n; i++)
    // {
    //     if (!vis[i])
    //     {
    //         dfs(i, -1, vis, insertionTime, low, timer, adj);
    //     }
    // }

    return 0;
}

/*
bcoz graph start from node 0
0 1 
1 2
2 3
3 0
3 4
4 5
5 6
6 7
7 8
8 5
7 9
9 10
10 11
11 9

bcoz graph start from node 1
1 2 
2 3
3 4
4 1
4 5
5 6
6 7
7 8
8 9
9 6
8 10
10 11
11 12
12 10
*/