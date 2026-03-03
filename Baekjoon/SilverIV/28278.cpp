#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    stack<int> s;

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

                s.push(x);
                break;
            }

            case 2:
            {
                if (s.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << s.top() << '\n';
                s.pop();
                break;
            }

            case 3:
            {
                cout << s.size() << '\n';
                break;
            }

            case 4:
            {
                cout << (s.empty() ? 1 : 0) << '\n';
                break;
            }

            case 5:
            {
                if (s.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << s.top() << '\n';
                break;
            }

            default:
                assert(false);
        }
    }

    return 0;
}