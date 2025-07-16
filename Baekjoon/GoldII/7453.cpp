#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> x(n * n), y (n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i * n + j] = a[i] + b[j];
            y[i * n + j] = c[i] + d[j];
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long result = 0;

    for (int i : x)
    {
        auto range = equal_range(y.begin(), y.end(), -i);
        result += distance(range.first, range.second);
    }

    cout << result;
}