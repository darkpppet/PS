#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    vector<int> indexes(dungeons.size());
    iota(indexes.begin(), indexes.end(), 0);
    
    int answer = 0;
    do
    {
        int count = 0, nowK = k;
        for (int i : indexes)
        {
            if (nowK >= dungeons[i][0])
                nowK -= dungeons[i][1];
            else
                break;
            count++;
        }
        
        answer = max(answer, count);
    } while (next_permutation(indexes.begin(), indexes.end()));
    
    
    return answer;
}

/*
int maxCount = 0;

void dfs(const vector<vector<int>>& dungeons, vector<bool>& check, int fatigue, int count)
{
    maxCount = max(maxCount, count);
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!check[i] && fatigue >= dungeons[i][0])
        {
            check[i] = true;
            dfs(dungeons, check, fatigue - dungeons[i][1], count + 1);
            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    vector<bool> check(dungeons.size());
    
    dfs(dungeons, check, k, 0);
    
    return maxCount;
}
*/