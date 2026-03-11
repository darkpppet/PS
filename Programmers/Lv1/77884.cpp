#include <string>
#include <vector>

using namespace std;

int countDivisors(int n)
{
    int answer = 1;
    for (int i = 2; i <= n; i++)
        answer += n % i == 0 ? 1 : 0;
    return answer;
}


int solution(int left, int right)
{
    int answer = 0;
    
    for (int i = left; i <= right; i++)
        answer += countDivisors(i) & 1 ? -i : i;
    
    return answer;
}