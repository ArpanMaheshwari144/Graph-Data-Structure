// Maximum Stone Removal [https://bit.ly/3QHZuE6]

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
        int maxRow=0;
        int maxCol=0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        // Here maxRow = 2 and maxCol = 2 ds(2+2+1) => 0 1 2 3 4 5
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            /*
            here nodeRow and nodeCol values are changed according to the stones array coordinates
            0(nodeRow) 3(nodeCol) 0 is ultimate parent of 3
            0(nodeRow) 4(nodeCol) 0 is ultimate parent of 4
            1(nodeRow) 3(nodeCol) 1 is ultimate parent of 3
            1(nodeRow) 5(nodeCol) 1 is ultimate parent of 5
            2(nodeRow) 4(nodeCol) 2 is ultimate parent of 4
            2(nodeRow) 5(nodeCol) 2 is ultimate parent of 5
            */
            
            // cout<<nodeRow<<" "<<nodeCol<<endl;
            
            /*
                            0
                        \ \ \ \ \
                        5  4 3 2 1
            Here is when we apply unionBySize and the loop is run successfully 0 is the ultimate parent of all the nodes
            */ 
            
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        
        // here we count how many ultimate parents there are
        int count=0;
        for(auto it : stoneNodes){
            if(ds.findUltimateParent(it.first) == it.first){
                count++;
            }
        }
        
        // total nodes - count of ultimate parents
        return n-count;
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
