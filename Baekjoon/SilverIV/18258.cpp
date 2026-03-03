#include <iostream>
#include <queue>
#include <cassert>
#include <unordered_map>

using namespace std;

enum class Operations
{
    Push, Pop, Size, Empty, Front, Back
};

const unordered_map<string, Operations> operationsMap
{
    {"push", Operations::Push},
    {"pop", Operations::Pop},
    {"size", Operations::Size},
    {"empty", Operations::Empty},
    {"front", Operations::Front},
    {"back", Operations::Back}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;

        switch (operationsMap.at(op))
        {
            case Operations::Push:
            {
                int x;
                cin >> x;

                q.push(x);
                break;
            }

            case Operations::Pop:
            {
                if (q.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << q.front() << '\n';
                q.pop();
                break;
            }

            case Operations::Size:
            {
                cout << q.size() << '\n';
                break;
            }

            case Operations::Empty:
            {
                cout << (q.empty() ? 1 : 0) << '\n';
                break;
            }

            case Operations::Front:
            {
                if (q.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << q.front() << '\n';
                break;
            }

            case Operations::Back:
            {
                if (q.empty())
                {
                    cout << -1 << '\n';
                    break;
                }

                cout << q.back() << '\n';
                break;
            }

            default:
                assert(false);
        }
    }

    return 0;
}