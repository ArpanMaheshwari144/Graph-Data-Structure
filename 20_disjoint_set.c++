#include <bits/stdc++.h>
using namespace std;

int parentArr[10000];
int rankArr[10000];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parentArr[i] = i;
        rankArr[i] = 0;
    }
}

int findParent(int node)
{
    if (node == parentArr[node])
    {
        return node;
    }

    return parentArr[node] = findParent(parentArr[node]);
}

void makeUnion(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (rankArr[u] < rankArr[v])
    {
        parentArr[u] = v;
    }
    else if (rankArr[v] < rankArr[u])
    {
        parentArr[v] = u;
    }
    else
    {
        parentArr[v] = u;
        rankArr[u]++;
    }
}

int main()
{
    int n = 7; //nodes
    makeSet(n);

    int m;
    cout << "Enter the number of operations: ";
    cin >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        makeUnion(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << rankArr[i] << " ";
    }

    return 0;
}

/*
union(1, 2) 
union(2, 3) 
union(4, 5) 
union(6, 7) 
union(5, 6) 
union(3, 7) 
Total n = 7 nodes(beacuse there is 7 which is maximum number)
Total number of operations = 6(because there are 6 union operation)
*/