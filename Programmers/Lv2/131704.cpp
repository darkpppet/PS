#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    stack<int> sub;

    int i = 0, now = 1;
    while (i < order.size() && now <= order.size())
    {
        if (order[i] == now)
        {
            now++;
            i++;
        }
        else if (!sub.empty() && sub.top() == order[i])
        {
            sub.pop();
            i++;
        }
        else
        {
            sub.push(now);
            now++;
        }
    }

    while (!sub.empty() && sub.top() == order[i])
    {
        sub.pop();
        i++;
    }

    return i;
}