#include <string>
#include <cctype>

using namespace std;

string solution(string s)
{
    string answer;
    char before = ' ';
    for (char c : s)
    {
        if (before == ' ')
            answer += toupper(c);
        else
            answer += tolower(c);
        
        before = c;
    }
    
    return answer;
}