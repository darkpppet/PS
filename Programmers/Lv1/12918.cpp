#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    if (s.size() != 4 && s.size() != 6)
        return false;
    
    for (char c : s)
    {
        if (c > '9' || c < '0')
            return false;
    }
    
    return true;
}