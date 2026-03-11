#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    vector<vector<int>> edgeV(n + 1);
    for (auto e : edge)
    {
        edgeV[e[0]].push_back(e[1]);
        edgeV[e[1]].push_back(e[0]);
    }
    
    vector<bool> check(n + 1);
    check[1] = true;
        
    queue<pair<int, int>> now;
    now.emplace(1, 0);
    
    int level = 0, count = 0;
    while (!now.empty())
    {
        auto [nowNode, nowLevel] = now.front();
        
        if (nowLevel > level)
        {
            level = nowLevel;
            count = 1;
        }
        else
        {
            count++;
        }
    
        for (auto e : edgeV[nowNode])
        {
            if (!check[e])
            {
                check[e] = true;
                now.emplace(e, nowLevel + 1);
            }
        }
        
        now.pop();
    }
    
    return count;
}