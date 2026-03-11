#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    constexpr int ascii0 = 48;
    int c = 0;
    string answer = "";
    for (int i = 0; i <= 100000; i++)
    {
        int t;
        if (i < a.size() && i < b.size())
        {
            t = a[i] + b[i] + c - 2 * ascii0;
        }
        else if (i < a.size())
        {
            t = a[i] + c - ascii0;
        }
        else if (i < b.size())
        {
            t = b[i] + c - ascii0;
        }
        else
        {
            if (c == 1)
                answer.append(1, '1');
            break;
        }
        
        if (t >= 10)
        {
            c = 1;
            t %= 10;
        }
        else
        {
            c = 0;
        }

        answer.append(1, t + ascii0);
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}