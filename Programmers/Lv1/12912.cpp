#include <string>

using namespace std;

long long solution(int a, int b)
{
    if (a > b)
        swap(a, b);
    
    long long answer = 0;
    for (long long i = a; i <= b; i++)
        answer += i;
    
    return answer;
}