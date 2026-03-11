#include <string>
#include <iostream>
#include <vector>
#include <charconv>

using namespace std;

int solution(string s)
{
    s += ' ';
    int answer = 0;
    int before = 0;
    string temp;
    
    for (char c: s)
    {
        if (c == '-' || (c >= '0' && c <= '9'))
        {
            temp += c;
        }
        else if (c == ' ')
        {
            int num = 0;
            from_chars(temp.data(), temp.data() + temp.size(), num);
            before = num;
            answer += num;
            
            temp.clear();
        }
        else if (c == 'Z')
        {
            answer -= before;
            
            temp.clear();
        }
    }
    
    return answer;
}