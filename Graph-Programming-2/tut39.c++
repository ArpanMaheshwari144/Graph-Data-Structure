// City With the Smallest Number of Neighbors at a Threshold Distance [https://bit.ly/3PoGo5v]

#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (auto it : edges)
    {
        // undirected graph
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    // floyd-warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int countCity = n;
    int cityNumber = -1;
    for (int city = 0; city < n; city++)
    {
        int count = 0;
        for (int adjCity = 0; adjCity < n; adjCity++)
        {
            if (dist[city][adjCity] <= distanceThreshold)
            {
                count++;
            }
        }
        if (count <= countCity)
        {
            countCity = count;
            cityNumber = city;
        }
    }
    return cityNumber;
}

int main()
{

    int n = 4, m = 4, dist = 4;
    vector<vector<int>> adj = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

    cout << "City Number: " << findCity(n, m, adj, dist) << "\n";

    return 0;
}
