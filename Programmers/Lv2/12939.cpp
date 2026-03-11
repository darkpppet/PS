#include <string>
#include <limits>
#include <cassert>

using namespace std;

string solution(string s)
{
    int minNumber = numeric_limits<int>::max();
    int maxNumber = numeric_limits<int>::min();
    
    s += ' ';
    string temp;
    for (char c : s)
    {
        if (c == ' ')
        {
            assert(!temp.empty());
            
            int n = stoi(temp);
            
            minNumber = min(minNumber, n);
            maxNumber = max(maxNumber, n);
            
            temp.clear();
            continue;
        }
        
        temp += c;
    }
    
    temp.clear();
    temp += to_string(minNumber);
    temp += ' ';
    temp += to_string(maxNumber);
    
    return temp;   
}