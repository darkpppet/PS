#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    if (n % 2 == 0)
    {
        answer = (n + 2) * (n + 1) * n / 6;
    }
    else
    {
        answer = (n + 1) * (n + 1) / 4;
    }

    return answer;
}

int main()
{
    cout << solution(7) << solution(10);
}