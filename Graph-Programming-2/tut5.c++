// Flood Fill Algorithm [https://bit.ly/3bxY94d]

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int iniColor)
{
    // color with new color
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    // there are exactly 4 neighbours
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        // Check for valid coordinates then check for the same initial color and unvisited pixel
        // checking if ans matrix does not have a newColor if it has a newColor so we do not do anything
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Get the initial color
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;

    // delta row and delta column for neighbors
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
    return ans;
}

int main()
{
    vector<vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    // sr = 1, sc = 1, newColor = 2
    vector<vector<int>> ans = floodFill(image, 1, 1, 2);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}
