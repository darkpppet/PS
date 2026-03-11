#include <string>

using namespace std;

bool solution(string s)
{
    int count = 0;
    
    for (char c : s)
    {
        if (c == '(')
        {
            count++;
        }
        else
        {
            if (count > 0)
                count--;
            else
                return false;
        }
    }
    
    return count == 0 ? true : false;
}