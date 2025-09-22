#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;

constexpr int calcDist(pair<int, int> p1, pair<int, int> p2)
{
    const int xd = p1.first - p2.first, yd = p1.second - p2.second;
    return xd * xd + yd * yd;
}

int calcMinDist(const vector<pair<int, int>>& points, const int left, const int right)
{
    if (right - left == 2)
    {
        const int l = left, r = left + 1;
        return calcDist(points[l], points[r]);
    }

    if (right - left == 3)
    {
        const vector<pair<int, int>> offsets { { 0, 1 }, { 0, 2 }, { 1, 2 }};
        int dist = numeric_limits<int>::max();
        for (const auto [lo, ro] : offsets)
        {
            const int l = left + lo, r = left + ro;
            dist = min(dist, calcDist(points[l], points[r]));
        }
        return dist;
    }

    const int mid = (left + right) / 2;
    int minDist = min(calcMinDist(points, left, mid), calcMinDist(points, mid, right));

    vector<pair<int, int>> s;
    s.reserve(right - left);
    for (int i = mid; i >= left; i--)
    {
        if (const int dx = points[mid].first - points[i].first; dx * dx >= minDist)
            break;
        s.emplace_back(points[i].second, points[i].first);
    }
    for (int i = mid + 1; i < right; i++)
    {
        if (const int dx = points[mid].first - points[i].first; dx * dx >= minDist)
            break;
        s.emplace_back(points[i].second, points[i].first);
    }

    ranges::sort(s);

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (const int yd = s[j].first - s[i].first; yd * yd >= minDist)
                break;

            minDist = min(minDist, calcDist(s[i], s[j]));
        }
    }

    return minDist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> points;
    points.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    ranges::sort(points);

    cout << calcMinDist(points, 0, points.size());
}