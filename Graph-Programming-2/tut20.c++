// Prerequisite Tasks [https://bit.ly/3ApDfOm]

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int V, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[V];
    for (auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

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

    if (topo.size() == V)
    {
        return true;
    }
    return false;
}

int main()
{
    int N = 4, P = 3;
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    bool ans = isPossible(N, prerequisites);
    if (ans)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}