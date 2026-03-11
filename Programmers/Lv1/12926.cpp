#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer;
    
    for (char c : s)
    {
        if (c == ' ')
        {
            answer += c;
            continue;
        }
        
        if (isupper(c))
        {
            answer += 'A' + (c - 'A' + n) % ('Z' - 'A' + 1);
            continue;
        }
        
        if (islower(c))
        {
            answer += 'a' + (c - 'a' + n) % ('z' - 'a' + 1);
            continue;
        }
    }
    
    return answer;
}