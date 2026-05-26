#include <string>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;
    
    while (n >= a)
    {
        int temp = b * (n / a);
        
        answer += temp;
        n %= a;
        n += temp;
    }
    
    return answer;
}