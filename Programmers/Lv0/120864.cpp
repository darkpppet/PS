#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    bool before_is_digit = false;
    int temp = 0;
    for (char c: my_string)
    {
        if (isdigit(c))
        {
            if (before_is_digit)
            {
                temp *= 10;
                temp += c - '0';
            }
            else
            {
                temp = c - '0';
                before_is_digit = true;
            }
        }
        else
        {
            if (before_is_digit)
            {
                answer += temp;
                temp = 0;
                before_is_digit = false;
            }
        }
    }
    
    answer += temp;
    
    return answer;
}