#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    vector<int> charStack;
    
    for (char c : s)
    {
        if (charStack.empty())
        {
            charStack.push_back(c);
            continue;
        }
        
        if (charStack.back() == c)
            charStack.pop_back();
        else
            charStack.push_back(c);
    }
    
    return charStack.empty() ? 1 : 0;
}