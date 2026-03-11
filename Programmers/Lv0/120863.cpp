#include <string>
#include <vector>

using namespace std;

string solution(string polynomial)
{
    polynomial += ' ';
    
    int x = 0, co = 0, coef = 0;
    
    for (char c : polynomial)
    {
        if (c >= '0' && c <= '9')
        {
            coef *= 10;
            coef += c - '0';
        }
        else if (c == 'x')
        {
            x += coef > 0 ? coef : 1;
            coef = 0;
        }
        else
        {
            co += coef;
            coef = 0;
        }
    }
    
    string result;
    if (x > 1)
        result += to_string(x);
    if (x >= 1)
        result += 'x';
    
    if (co > 0)
    {
        if (x >= 1)
            result += " + ";
        result += to_string(co);
    }
    
    return result;
}