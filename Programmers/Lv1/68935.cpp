#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    while (n > 0)
    {
        answer *= 3;
        answer += n % 3;
        n /= 3;
    }
    
    return answer;
}