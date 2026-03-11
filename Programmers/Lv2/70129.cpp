#include <string>
#include <vector>
#include <cassert>

using namespace std;

string to_string_base2(int num)
{
    assert(num >= 0);
    
    if (num == 0)
        return "0";
        
    string answer;
    while (num > 0)
    {
        answer += (num & 1) + '0';
        num >>= 1;
    }
    return answer;
}

vector<int> solution(string s)
{
    if (s == "1")
        return { 0, 0 };
    
    int tCount = 0, zCount = 0;
    while (s != "1")
    {
        int oCount = 0;
        for (char c : s)
        {
            if (c == '1')
                oCount++;
            else
                zCount++;
        }
    
        s = to_string_base2(oCount);
        tCount++;
    }
    
    return { tCount, zCount };
}