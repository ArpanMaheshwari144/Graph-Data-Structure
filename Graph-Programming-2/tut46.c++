// Number of Islands - II - Online Queries [https://bit.ly/3w9REfj]

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
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
    bool isValid(int adjR, int adjC, int n, int m)
    {
        return adjR >= 0 && adjR < n && adjC >= 0 && adjC < m;
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int count = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            count++;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int index = 0; index < 4; index++)
            {
                int adjR = row + dr[index];
                int adjC = col + dc[index];
                if (isValid(adjR, adjC, n, m))
                {
                    if (vis[adjR][adjC] == 1)
                    {
                        int nodeNumber = row * m + col; // calculating the node number cell in the 2-D Matrix
                        int adjNodeNumber = adjR * m + adjC;
                        if (ds.findUltimateParent(nodeNumber) != ds.findUltimateParent(adjNodeNumber))
                        {
                            count--;
                            ds.unionBySize(nodeNumber, adjNodeNumber);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main()
{
    int n = 4, m = 5, k = 4;
    vector<vector<int>> adj = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};

    Solution obj;
    vector<int> res = obj.numOfIslands(n, m, adj);

    for (auto x : res)
    {
        cout << x << " ";
    }

    return 0;
}