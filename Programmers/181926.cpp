#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, string control)
{
    int answer = 0;
    answer = n;

    for (char c : control)
    {
        switch (c)
        {
            case 'w':
                answer += 1;
                break;
            case 's':
                answer -= 1;
                break;
            case 'd':
                answer += 10;
                break;
            case 'a':
                answer -= 10;
                break;
        }
    }

    return answer;
}

int main()
{
    cout << solution(0, "wsdawsdassw");
}