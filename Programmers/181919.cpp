#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer{ n };
    int now = n;
    while (now != 1)
    {
        if (now % 2 == 0)
        {
            now /= 2;
        }
        else
        {
            now = 3 * now + 1;
        }
        answer.push_back(now);
    }
    return answer;
}

int main()
{
    auto result = solution(10);
    for (int i : result)
    {
        cout << i << ' ';
    }
}