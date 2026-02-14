#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int inf = numeric_limits<int>::max() / 2;

int main()
{
    int n;
    cin >> n;

    vector<int> r(n), g(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> r[i] >> g[i] >> b[i];

    int answer = inf;
    {
        int dpR = r[0];
        int dpG = inf;
        int dpB = inf;
        for (int i = 1; i < n; i++)
        {
            int dpRt = r[i] + min(dpG, dpB);
            int dpGt = g[i] + min(dpB, dpR);
            int dpBt = b[i] + min(dpR, dpG);
            swap(dpR, dpRt);
            swap(dpG, dpGt);
            swap(dpB, dpBt);
        }
        answer = min(answer, min(dpG, dpB));
    }

    {
        int dpR = inf;
        int dpG = g[0];
        int dpB = inf;
        for (int i = 1; i < n; i++)
        {
            int dpRt = r[i] + min(dpG, dpB);
            int dpGt = g[i] + min(dpB, dpR);
            int dpBt = b[i] + min(dpR, dpG);
            swap(dpR, dpRt);
            swap(dpG, dpGt);
            swap(dpB, dpBt);
        }
        answer = min(answer, min(dpB, dpR));
    }

    {
        int dpR = inf;
        int dpG = inf;
        int dpB = b[0];
        for (int i = 1; i < n; i++)
        {
            int dpRt = r[i] + min(dpG, dpB);
            int dpGt = g[i] + min(dpB, dpR);
            int dpBt = b[i] + min(dpR, dpG);
            swap(dpR, dpRt);
            swap(dpG, dpGt);
            swap(dpB, dpBt);
        }
        answer = min(answer, min(dpR, dpG));
    }

    cout << answer;

    return 0;
}