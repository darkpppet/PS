#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    list<pair<int, int>> balloons;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        balloons.emplace_back(i, num);
    }

    auto it = balloons.begin();
    while (balloons.size() > 1)
    {
        cout << it->first << ' ';

        const int nextSize = static_cast<int>(balloons.size() - 1);
        int move = it->second;
        if (move > 0)
            move = (move - 1) % nextSize;
        else
            move = ((move % nextSize) + nextSize) % nextSize;

        it = balloons.erase(it);
        if (it == balloons.end())
            it = balloons.begin();

        for (int i = 0; i < move; i++)
        {
            it = next(it);
            if (it == balloons.end())
                it = balloons.begin();
        }
    }
    cout << balloons.front().first << ' ';

    return 0;
}