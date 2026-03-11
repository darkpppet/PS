#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 1;
    int now = 1;
    
    while (now < n)
    {
        answer++;
        if (answer % 3 != 0 && to_string(answer).find('3') == string::npos)
            now++;
    }
    
    return answer;
}