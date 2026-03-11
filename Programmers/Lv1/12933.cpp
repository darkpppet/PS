#include <string>
#include <iostream>
#include <array>

using namespace std;

long long solution(long long n)
{
    array<int, 10> digits {};
    while (n > 0)
    {
        digits.at(n % 10)++;
        n /= 10;
    }
    
    long long answer = 0;
    int index = 9;
    while (index >= 0)
    {
        if (digits.at(index) > 0)
        {
            answer *= 10;
            answer += index;
            digits.at(index)--;
            continue;
        }
        
        index--;
    }
    
    return answer;
}