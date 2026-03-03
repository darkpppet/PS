#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> lessPq;
    priority_queue<int, vector<int>, greater<>> greaterPq;
    {
        int num;
        cin >> num;
        lessPq.push(num);
        cout << num << '\n';
    }

    for (int j = 2; j <= n; j++)
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

            cout << min(lessPq.top(), greaterPq.top()) << '\n';
        }
        else
        {
            if (greaterPq.size() > lessPq.size())
            {
                lessPq.push(greaterPq.top());
                greaterPq.pop();
            }

            cout << lessPq.top() << '\n';
        }
    }

    return 0;
}