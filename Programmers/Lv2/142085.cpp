#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    priority_queue<int> hardest;
    for (int i = 0; i < enemy.size(); i++)
    {
        if (k > 0)
            hardest.push(enemy[i]);
        
        if (n >= enemy[i])
        {
            n -= enemy[i];
        }
        else if (k > 0)
        {
            n += hardest.top();
            n -= enemy[i];
            hardest.pop();
            k--;
            if (k == 0)
                hardest = priority_queue<int>();
        }
        else
        {
            return i;
        }
    }
    
    return enemy.size();
}