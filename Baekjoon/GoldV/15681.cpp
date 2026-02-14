#include <iostream>
#include <vector>

using namespace std;

int calcChildren(const int node, const vector<vector<int>>& neighbors, vector<int>& childrenCount, vector<bool>& visited)
{
    int count = 1;
    visited[node] = true;
    for (const int children: neighbors[node])
    {
        if (visited[children])
            continue;

        count += calcChildren(children, neighbors, childrenCount, visited);
    }
    childrenCount[node] = count;
    return count;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> neighbors(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    vector<int> children(n + 1);
    vector<bool> visited(n + 1);

    calcChildren(r, neighbors, children, visited);

    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;

        cout << children[u] << '\n';
    }

    return 0;
}