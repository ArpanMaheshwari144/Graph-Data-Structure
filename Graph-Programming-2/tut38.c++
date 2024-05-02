// Floyd Warshall [https://bit.ly/3JZlk4a]

#include <bits/stdc++.h>
using namespace std;

/*
Multisource shortest path algo and also detect negative cycle
*/
void floydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if (i == j)
            {
                matrix[i][j] == 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /* 
                compute matrix[1][2] moving via vertex 0
                matrix[1][2] = min(matrix[1][2], matrix[1][0] + matrix[0][2])
                
                compute matrix[0][2] moving via vertex 1
                matrix[0][2] = min(matrix[0][2], matrix[0][1] + matrix[1][2])

                compute matrix[0][2] moving via vertex 2
                and so on...
                */
                // matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j])
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            cout << "Graph contains negative cycle";
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};

    floydWarshall(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
