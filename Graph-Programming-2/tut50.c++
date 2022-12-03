// Bridges in Graph | Critical Connections in a Network [https://leetcode.com/problems/critical-connections-in-a-network/]

#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int timeOfInsertion[], int lowestTimeOfInsertion[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    timeOfInsertion[node] = lowestTimeOfInsertion[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
        {
            continue;
        }

        if (vis[it] == 0)
        {
            dfs(it, node, vis, adj, timeOfInsertion, lowestTimeOfInsertion, bridges);
            lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], lowestTimeOfInsertion[it]);

            // node --> it
            if (lowestTimeOfInsertion[it] > timeOfInsertion[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            lowestTimeOfInsertion[node] = min(lowestTimeOfInsertion[node], lowestTimeOfInsertion[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    int timeOfInsertion[n];
    int lowestTimeOfInsertion[n];
    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, timeOfInsertion, lowestTimeOfInsertion, bridges);
    return bridges;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> bridges = criticalConnections(n, connections);
    for (int i = 0; i < bridges.size(); i++)
    {
        for (int j = 0; j < bridges[i].size(); j++)
        {
            cout << bridges[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}