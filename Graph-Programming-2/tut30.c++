// Dijkstra Algorithm using Set  [https://bit.ly/3KeZZ7j]

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // set stores everything in the ascending order
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    st.insert({0, S}); // (dist, node)
    dist[S] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it); // similar to pop operation

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];

            // we found someone better distance than the previous one so we have to remove the previous one and add the better one
            if (dis + edgeWeight < dist[adjNode])
            {
                // erase if it exists
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{

    int V = 3, E = 3;
    vector<vector<int>> adj[V] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int src = 2;

    vector<int> res = dijkstra(V, adj, src);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
