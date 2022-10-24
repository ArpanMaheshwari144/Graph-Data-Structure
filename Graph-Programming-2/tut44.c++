// Number of Operations to Make Network Connected [https://bit.ly/3QGtkcd]

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        // resize means it will shrink according to the size, otherwise it will be the same size as we declared
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if (ultimateParentU == ultimateParentV)
        {
            return;
        }

        if (rank[ultimateParentU] < rank[ultimateParentV])
        {
            parent[ultimateParentU] = ultimateParentV;
        }
        else if (rank[ultimateParentV] < rank[ultimateParentU])
        {
            parent[ultimateParentV] = ultimateParentU;
        }
        else
        {
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if (ultimateParentU == ultimateParentV)
        {
            return;
        }

        if (size[ultimateParentU] < size[ultimateParentV])
        {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        }
        else
        {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);
        int countExtraEdges = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];

            if (ds.findUltimateParent(u) == ds.findUltimateParent(v))
            {
                countExtraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        int countComponents = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
            {
                countComponents++;
            }
        }
        int ans = countComponents - 1;
        if (countExtraEdges >= ans)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int n = 6; // n = 6 means 0-5 vertices
    vector<vector<int>> adj = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

    Solution obj;
    cout << obj.Solve(n, adj);

    return 0;
}