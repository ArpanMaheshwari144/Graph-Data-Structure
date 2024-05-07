// Number of Enclaves [https://bit.ly/3preQSc]

#include <bits/stdc++.h>
using namespace std;

int numberOfEnclaves(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m] = {0};

    // traverse boundary elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // first row, first col, last row, last col
            // 
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                // if it is land then store it in the queue
                // We are storing all the boundaries 1 in the queue and mark them as visited
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, +0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverses all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // check for valid coordinates and land cell
            //  Only those cells that are present in the boundary or in the boundary path are visited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    // Here we count only those cells which are not visited(which means they are not present in the boundary or boundary path)
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check for unvisited land cell
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    cout << numberOfEnclaves(grid) << endl;

    return 0;
}
