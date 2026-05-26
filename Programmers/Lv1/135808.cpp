#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    vector<int> scoreCounts(k + 1);
    for (int s : score)
        scoreCounts[s]++;
    
    int answer = 0;
    int pointer = k;
    
    for (int i = 0; i < score.size() / m; i++)
    {
        int remain = m;
        while (remain > 0)
        {
            if (scoreCounts[pointer] >= remain)
            {
                scoreCounts[pointer] -= remain;
                break;
            }
            
            remain -= scoreCounts[pointer];
            pointer--;
        }
        
        answer += pointer * m;
    }
    
    return answer;
}