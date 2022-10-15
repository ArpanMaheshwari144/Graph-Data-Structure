// Course Schedule [https://bit.ly/3SYjQvp]

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
{
    vector<int> adj[V];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
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
        return topo;
    }
    return {};
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> prerequisites = {{{1, 0}, {2, 0}, {3, 1}, {3, 2}}};

    vector<int> ans = findOrder(n, m, prerequisites);
    if (ans.size() == 0)
    {
        cout << "No Ordereing is possible";
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}
