#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <bitset>

using namespace std;

using CostAndDest = pair<int, int>;

int solution(int n, vector<vector<int>> costs)
{
    vector<vector<CostAndDest>> edgeCosts(n);
    for (auto cost : costs)
    {
        edgeCosts[cost[0]].emplace_back(-cost[2], cost[1]);
        edgeCosts[cost[1]].emplace_back(-cost[2], cost[0]);
    }
    
    priority_queue<CostAndDest> edges;
    for (auto k : edgeCosts[0])
        edges.push(k);
    
    bitset<100> check;
    check.set(0);
    int answer = 0;
    
    for (int i = 1; i < n; i++)
    {
        while (check.test(edges.top().second))
            edges.pop();
        
        answer += edges.top().first;
        int nowNode = edges.top().second;
        check.set(nowNode);
        edges.pop();
        
        for (auto k : edgeCosts[nowNode])
        {
            if (!check.test(k.second))
                edges.push(k);
        }
    }
    
    return -answer;
}