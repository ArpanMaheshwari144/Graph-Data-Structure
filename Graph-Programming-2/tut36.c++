// Number of Ways to Arrive at Destination [https://bit.ly/3Aro6Mq]

#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> timeArray(n, 1e9), ways(n, 0);
    timeArray[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // (time, node)
    int mod = (int)(1e9 + 7);
    while (!pq.empty())
    {
        int timeToReach = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeTime = it.second;

            // this is the first time we have reached this node in short distance
            if (timeToReach + edgeTime < timeArray[adjNode])
            {
                timeArray[adjNode] = timeToReach + edgeTime;
                pq.push({timeArray[adjNode], adjNode});
                ways[adjNode] = ways[node];
            }
            else if (timeToReach + edgeTime == timeArray[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1];
}

int main()
{
    int n = 7, m = 10;
    vector<vector<int>> adj = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout << "The number of ways you can arrive at your destination in the shortest amount of time is: " << countPaths(n, adj) << "\n";

    return 0;
}