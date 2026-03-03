#include <iostream>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    {
        bitset<100'000> isQueue;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a == 0)
                isQueue.set(i);
        }
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            if (isQueue.test(i))
                s.push(b);
        }
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;

        q.push(c);
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}