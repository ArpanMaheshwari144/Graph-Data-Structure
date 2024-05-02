// Distance from the Source (Bellman-Ford Algorithm) [https://bit.ly/3K7emug]

#include <bits/stdc++.h>
using namespace std;

/*
In Bellman Ford we always do n-1(n is the number of nodes) relaxation but why?
Bcoz for every relaxation:
If we do 1st time relaxation the 0th node answers its adjacent node
and then the 0th adjacent node answers its adjacent nodes and so on...
*/
/*
if we do n-1 relaxation and the distance array is reduced on nth relaxation as well this means there is negative cycle
*/
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Nth relaxation to check negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}

int main()
{

    int N = 3, src = 2;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};

    vector<int> res = bellmanFord(N, edges, src);
    for (auto x : res)
    {
        cout << x << " ";
    }

    return 0;
}
