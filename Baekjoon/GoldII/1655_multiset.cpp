#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    multiset<int> ms;
    multiset<int>::iterator it;
    {
        int num;
        cin >> num;
        ms.insert(num);
        cout << num << '\n';
        it = ms.begin();
    }

    for (int j = 2; j <= n; j++)
    {
        int num;
        cin >> num;

        ms.insert(num);

        if (j % 2 == 0)
        {
            if (num >= *it)
                ++it;
            cout << min(*prev(it), *it) << '\n';
        }
        else
        {
            if (num < *it)
                --it;
            cout << *it << '\n';
        }
    }

    return 0;
}