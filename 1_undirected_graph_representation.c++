// we draw the graph from node 0, if we started all the loops from 0.
// we draw the graph from node 1, if we not started all the loops from 0.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // declare the adjacent matrix
    int adj[n + 1][n + 1]; // n+1 size bcoz of assuming 1 based indexing in the graph

    // take edges as input
    cout << "Enter the edges of the graph\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}