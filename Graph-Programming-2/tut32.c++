// Shortest Distance in a Binary Maze [https://bit.ly/3QLxjET]

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    // if source == destination
    if (source == destination)
    {
        return 0;
    }

    // (dist, {row, col})
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto it = q.front();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            // there are only four directions
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 1 && dis + 1 < dist[newRow][newCol])
            {
                dist[newRow][newCol] = 1 + dis; // 1 + (bcoz of unit distance)
                if (newRow == destination.first && newCol == destination.second)
                {
                    return 1 + dis;
                }
                q.push({1 + dis, {newRow, newCol}});
            }
        }
    }
    return -1;
}

int main()
{
    pair<int, int> source = {0, 1}, destination = {2, 2};
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    cout << "Shortest Path: " << shortestPath(grid, source, destination) << endl;

    return 0;
}
