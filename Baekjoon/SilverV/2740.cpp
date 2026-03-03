#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    int k;
    cin >> m >> k;
    vector<vector<int>> b(m);
    for (int i = 0; i < m; i++)
    {
        b[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> b[i][j];
    }

    vector<vector<int>> result(n);
    for (vector<int>& row : result)
        row.resize(k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < m; l++)
                result[i][j] += a[i][l] * b[l][j];
        }
    }

    for (const vector<int>& row : result)
    {
        for (const int element : row)
            cout << element << ' ';
        cout << '\n';
    }

    return 0;
}