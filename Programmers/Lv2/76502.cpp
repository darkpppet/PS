#include <string>
#include <vector>

using namespace std;

bool isCorrect(const string& s)
{
    vector<char> stackChar;
    
    for (char c : s)
    {
        if (c == ')' || c == ']' || c == '}')
        {
            if (stackChar.empty())
                return false;
            
            char needBack;
            switch (c)
            {
                case ')':
                    needBack = '(';
                    break;
                case ']':
                    needBack = '[';
                    break;
                case '}':
                    needBack = '{';
                    break;
            }
            if (stackChar.back() != needBack)
                return false;
            
            stackChar.pop_back();
        }
        else
        {
            stackChar.push_back(c);
        }
    }
    
    return stackChar.empty() ? true : false;
}

int solution(string s)
{
    int answer = 0;
    string ss = s + s;
    for (int i = 0; i < s.size(); i++)
    {
        string subs(ss.begin() + i, ss.begin() + s.size() + i);
        if (isCorrect(subs))
            answer++;
    }
    return answer;
}