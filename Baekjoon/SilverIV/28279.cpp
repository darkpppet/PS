#include <iostream>
#include <deque>
#include <cassert>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    deque<int> d;

    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;

        switch (op)
        {
            case 1:
            {
                int x;
                cin >> x;

                d.push_front(x);
                break;
            }

            case 2:
            {
                int x;
                cin >> x;

                d.push_back(x);
                break;
            }

            case 3:
            {
                if (d.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << d.front() << '\n';
                d.pop_front();
                break;
            }

            case 4:
            {
                if (d.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << d.back() << '\n';
                d.pop_back();
                break;
            }

            case 5:
            {
                cout << d.size() << '\n';
                break;
            }

            case 6:
            {
                cout << (d.empty() ? 1 : 0) << '\n';
                break;
            }

            case 7:
            {
                if (d.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << d.front() << '\n';
                break;
            }

            case 8:
            {
                if (d.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << d.back() << '\n';
                break;
            }

            default:
                assert(false);
        }
    }

    return 0;
}