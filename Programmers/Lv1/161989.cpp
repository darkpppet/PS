#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    vector<bool> wall(n + 1);
    for (int need : section)
        wall[need] = true;
    
    int answer = 0;
        
    for (int need : section)
    {
        if (wall[need] == false)
            continue;
        
        for (int i = need; i < min(need + m, n + 1); i++)
            wall[i] = false;
        answer++;
    }
    
    return answer;
}