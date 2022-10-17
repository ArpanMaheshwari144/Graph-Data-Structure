// Path With Minimum Effort [https://bit.ly/3dMBvq6]

#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto it = pq.top();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        pq.pop();

        if (row == n - 1 && col == m - 1)
        {
            return diff;
        }

        // there are only 4 directions
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
            {
                int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), diff);
                if (newEffort < dist[newRow][newCol])
                {
                    dist[newRow][newCol] = newEffort;
                    pq.push({newEffort, {newRow, newCol}});
                }
            }
        }
    }
    return 0;
}

int main()
{

    int n = 3, m = 3;
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << MinimumEffort(heights) << "\n";

    return 0;
}
