#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m;

        cout << (m + 1) / 2 << '\n';

        multiset<int> ms;
        multiset<int>::iterator it;
        {
            int num;
            cin >> num;
            ms.insert(num);
            cout << num << ' ';
            it = ms.begin();
        }

        int printCount = 1;
        for (int j = 2; j <= m; j++)
        {
            int num;
            cin >> num;

            ms.insert(num);

            if (j % 2 == 0)
            {
                if (num >= *it)
                    ++it;
            }
            else
            {
                if (num < *it)
                    --it;
                cout << *it << ' ';
                printCount++;
                if (printCount == 10)
                {
                    cout << '\n';
                    printCount = 0;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}