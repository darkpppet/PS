#include <string>
#include <array>

using namespace std;

const array<string, 10> arr
{
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

bool isMatch(const string& origin, const string::const_iterator start, const string& pattern)
{
    string::const_iterator originIt = start;
    string::const_iterator patternIt = pattern.cbegin();
    
    while (originIt < origin.cend() && patternIt < pattern.cend())
    {
        if (*originIt != *patternIt)
            return false;
        
        ++originIt;
        ++patternIt;
    }
    
    return patternIt == pattern.end();
}


int solution(string s)
{
    string llStr;
    string::const_iterator it = s.cbegin();
    
    while (it < s.cend())
    {
        if (isdigit(*it))
        {
            llStr += *it;
            ++it;
            continue;
        }
        
        for (int i = 0; i < 10; i++)
        {
            if (isMatch(s, it, arr[i]))
            {
                llStr += to_string(i);
                it += arr[i].size();
                break;
            }
        }
    }
    
    return stoll(llStr);
}