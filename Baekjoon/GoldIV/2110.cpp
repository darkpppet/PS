#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkDistance(const int d, const int c, const vector<int> &x)
{
    int count = 1;
    int before = x.front();
    for (const int point : x)
    {
        if (point - before >= d)
        {
            before = point;
            count++;

            if (count >= c)
                return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<int> x;
    x.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int xi;
        cin >> xi;
        x.push_back(xi);
    }

    ranges::sort(x);

    int minD = 1;
    int maxD = x.back() - x.front();

    if (checkDistance(maxD, c, x))
    {
        cout << maxD;
        return 0;
    }

    while (maxD - minD > 1)
    {
        const int middle = (minD + maxD) / 2;

        if (checkDistance(middle, c, x))
            minD = middle;
        else
            maxD = middle;
    }
    cout << minD;

    return 0;
}