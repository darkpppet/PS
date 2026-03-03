#include <iostream>
#include <queue>

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

        priority_queue<int> lessPq;
        priority_queue<int, vector<int>, greater<>> greaterPq;
        {
            int num;
            cin >> num;
            lessPq.push(num);
            cout << num << ' ';
        }

        int printCount = 1;
        for (int j = 2; j <= m; j++)
        {
            int num;
            cin >> num;

            if (num <= lessPq.top())
                lessPq.push(num);
            else
                greaterPq.push(num);

            if (j % 2 == 0)
            {
                if (lessPq.size() > greaterPq.size() + 1)
                {
                    greaterPq.push(lessPq.top());
                    lessPq.pop();
                }
            }
            else
            {
                if (greaterPq.size() > lessPq.size())
                {
                    lessPq.push(greaterPq.top());
                    greaterPq.pop();
                }

                cout << lessPq.top() << ' ';
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