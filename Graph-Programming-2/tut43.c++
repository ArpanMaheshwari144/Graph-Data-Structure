// Number of Provinces using DisjointSet [https://bit.ly/3pl2tr3]

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        // resize means it will shrink according to the size, otherwise it will be the same size as we declared
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
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
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If there is one this means there is an edge between i & j and we attach i & j
                if (adj[i][j] == 1)
                {
                    ds.unionByRank(i, j);
                }
            }
        }

        /*
        1-2-3 4-5 6-7 Here we have 3 provinces
        if we take the parents of everyone it will be like this:

         1      4    6
        / \     |    |
       2   3    5    7

        parent[1] = 1
        parent[2] = 1
        parent[3] = 1

        parent[4] = 4
        parent[5] = 4

        parent[6] = 6
        parent[7] = 6

        so here we can easily see that if we broke this into something like this we can see that if we find the 
        the ultimate parent of 1 & 2 & 3 = 1, for 4 & 5 = 4 and for 6 & 7 = 6
        */
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.findUltimateParent(i) == i)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{

    int V = 3;
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    Solution ob;
    cout << "Connected components are: " << ob.numProvinces(adj, V);

    return 0;
}
