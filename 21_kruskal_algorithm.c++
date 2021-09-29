#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt; // sort according to weight
}

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rankArr)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rankArr[u] < rankArr[v])
    {
        parent[u] = v;
        rankArr[v] += rankArr[u];
    }
    else
    {
        parent[v] = u;
        rankArr[u] += rankArr[v];
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<node> edges;

    // take edges as input
    cout << "Enter the edges along with weight of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    // if graph start from node 0
    // vector<int> parent(n);
    // for (int i = 0; i < n; i++)
    // {
    //     parent[i] = i;
    // }

    // if graph start from node 1
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<int> rankArr(n, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findParent(it.v, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back(make_pair(it.u, it.v));
            unionn(it.u, it.v, parent, rankArr);
        }
    }

    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;

    // OR

    // for (auto it = mst.begin(); it != mst.end(); it++)
    // {
    //     cout << it->first << " - " << it->second << endl;
    // }

    return 0;
}

/*
Graph starts from node 0
0 3 1
0 1 2
0 4 4
1 2 3
1 3 3
1 5 7
2 5 8
2 3 5
3 4 9

Graph starts from node 1
1 2 2
1 4 1
1 5 4
2 3 3
2 4 3
2 6 7
3 4 5
3 6 8
4 5 9
*/