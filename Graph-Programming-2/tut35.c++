// Minimum Multiplications to reach End [https://bit.ly/3AugzNb]

#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    queue<pair<int, int>> q;
    // (number, steps)
    q.push({start, 0});
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            // Multiply the current number and queue number and see that it is smaller than we stored in the dist array
            // as we in increase the steps by one bcoz we did multiply
            int num = (it * node) % 100000;
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if (num == end)
                {
                    return steps + 1;
                }
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}

int main()
{

    int start = 3, end = 30;
    vector<int> arr = {2, 5, 7};

    cout << "Minimum steps are: " << minimumMultiplications(arr, start, end) << endl;

    return 0;
}
