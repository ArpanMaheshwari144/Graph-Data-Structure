// Disjoint Set | Union by Rank | Union by Size | Path Compression

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
        // Path Compression
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

        /* We attached a smaller to a bigger one bcoz in the graph height will not increase and the travel time for finding the parent 
        will also decrease */
        // If U is less than V then U is attached to V
        // smaller is attached to the bigger one so in the rank array there is no change
        if (rank[ultimateParentU] < rank[ultimateParentV])
        {
            parent[ultimateParentU] = ultimateParentV;
        }
        // If V is less than U then V is attached to U
        // smaller is attached to the bigger one so in the rank array there is no change
        else if (rank[ultimateParentV] < rank[ultimateParentU])
        {
            parent[ultimateParentV] = ultimateParentU;
        }
        // If both ranks are equal if we attached to anyone either case rank also increases
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

int main()
{
    // Using Union-By-Rank
    // DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);

    // Using Union-By-Size
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    // ds.unionByRank(3, 7);
    ds.unionBySize(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not same\n";
    }

    return 0;
}
