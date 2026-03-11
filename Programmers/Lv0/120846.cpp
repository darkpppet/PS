#include <string>
#include <vector>

using namespace std;

bool is_prime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!is_prime(i))
        {
            answer++;
        }
    }
    
    return answer;
}