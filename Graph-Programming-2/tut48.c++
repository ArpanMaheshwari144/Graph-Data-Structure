// Maximum Stone Removal [https://bit.ly/3QHZuE6]
// Question -> [[0 0] ,[ 0 1], [1 0] ,[1 2] ,[2 1] ,[2 2]] Gives the co-ordinates of the matrix

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
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Here we are finding the dimensions of the matrix 
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // counting the connected components
        int count = 0; // (number of components)
        for (auto it : stoneNodes)
        {
            // counting the number of parents of the current node(means the bosses)
            if (ds.findUltimateParent(it.first) == it.first)
            {
                count++;
            }
        }
        /*
        If we have n stones:
        Component1  Component2  Component3  Component4
        x1 stones   x2 stones   x3 stones  x4 stones ===> x1 + x2 + x3 + x4 + ....... + = n ----- equation 1
        In 1 component we remove all the stones apart from the 1 stone(from the same row and the same col as the question said)
        (x1-1) + (x2-1) + (x3-1) + (x4-1) + .....
        (x1 + x2 + x3 + x4) - (1 + 1 + 1 + 1 + 1)
        from equation 1
        n - (number of components)
        */
        return n - count;
    }
};

int main()
{
    int n = 6;
    vector<vector<int>> adj = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

    Solution obj;
    cout << "The maximum possible number of stones that you can remove: " << obj.maxRemove(adj, n);

    return 0;
}
