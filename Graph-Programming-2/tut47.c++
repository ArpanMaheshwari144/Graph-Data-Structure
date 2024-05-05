// Making a Large Island | Maximum Connected group [https://bit.ly/3xeLjzF]

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
    bool isValid(int newRow, int newCol, int n)
    {
        return newRow >= 0 && newRow < n && newCol >= 0 && newCol < n;
    }

    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Connecting the components
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int index = 0; index < 4; index++)
                {
                    int newRow = row + dr[index];
                    int newCol = col + dc[index];
                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1)
                    {
                        int nodeNumber = row * n + col;
                        int adjNodeNumber = newRow * n + newCol;
                        ds.unionBySize(nodeNumber, adjNodeNumber);
                    }
                }
            }
        }

        // Trying to convert the 0's to 1 and making the large component
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // If we encounter the 1 we do not convert this
                if (grid[row][col] == 1)
                {
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int index = 0; index < 4; index++)
                {
                    int newRow = row + dr[index];
                    int newCol = col + dc[index];
                    if (isValid(newRow, newCol, n))
                    {
                        // If the new row and new col are valid it will be 1 otherwise it will never be a component
                        if (grid[newRow][newCol] == 1)
                        {
                            // (newRow * n + newCol) for this cell number give the ultimate parent
                            // Get all the components that we can connect
                            /* In the set we only store the ultimate parent of the cell number bcoz if we store the sizes directly 
                            so it will give the wrong answer */
                            // Why set bcoz if we encounter two same parent of the components
                            components.insert(ds.findUltimateParent(newRow * n + newCol));
                        }
                    }
                }

                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1); // + 1  for we convert a 0 to 1
            }
        }

        // If the cell has all ones
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            mx = max(mx, ds.size[ds.findUltimateParent(cellNo)]);
        }
        return mx;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 1}, {0, 1}};

    Solution obj;
    cout << "The largest group of connected 1's size is: " << obj.MaxConnection(grid);

    return 0;
}
