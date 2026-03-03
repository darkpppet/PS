#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    stack<int> wait;

    int now = 1;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == now)
        {
            now++;
            continue;
        }

        while (!wait.empty() && wait.top() == now)
        {
            wait.pop();
            now++;
        }

        wait.push(num);
    }

    while (!wait.empty() && wait.top() == now)
    {
        wait.pop();
        now++;
    }

    cout << (wait.empty() ? "Nice" : "Sad");

    return 0;
}