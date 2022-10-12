// Number of Islands [https://bit.ly/3oT9Ndg]

#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vis[row][col] = 1;
    q.push({row, col});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse the neighbours and mark them if its a land
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int neighbourRow = row + delrow;
                int neighbourCol = col + delcol;
                if (neighbourRow >= 0 && neighbourRow < n && neighbourCol >= 0 && neighbourCol < m && grid[neighbourRow][neighbourCol] == '1' && !vis[neighbourRow][neighbourCol])
                {
                    vis[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow, neighbourCol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                count++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {{'0', '1'},
                                 {'1', '0'},
                                 {'1', '1'},
                                 {'1', '0'}};

    int ans = numIslands(grid);
    cout << "The number of islands: " << ans;

    return 0;
}
