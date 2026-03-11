#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    
    for (auto s = t.begin(); s <= t.end() - p.size(); s++)
    {
        for (int i = 0; i < p.size(); i++)
        {
            if (*(s + i) == *(p.begin() + i))
            {
                if (i == p.size() - 1)
                    answer++;
                continue;
            }
            
            if (*(s + i) < *(p.begin() + i))
                answer++;
                
            break;
        }
    }
    
    return answer;
}