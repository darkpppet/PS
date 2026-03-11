#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <unordered_set>

using namespace std;

constexpr int INF = 987654321;

int solution(int N, vector<vector<int>> road, int K)
{
    vector<vector<pair<int, int>>> edges(N + 1);
    {
        vector<unordered_map<int, int>> memo(N + 1);
        for (auto r : road)
        {
            if (memo[r[0]].find(r[1]) != memo[r[0]].end())
                memo[r[0]][r[1]] = min(memo[r[0]][r[1]], r[2]);
            else
                memo[r[0]].emplace(r[1], r[2]);
            
            if (memo[r[1]].find(r[0]) != memo[r[1]].end())
                memo[r[1]][r[0]] = min(memo[r[1]][r[0]], r[2]);
            else
                memo[r[1]].emplace(r[0], r[2]);
        }
        
        for (int i = 1; i <= N; i++)
        {
            for (auto [e, c] : memo[i])
                edges[i].emplace_back(c, e);
        }
    }
    
    vector<int> distance(N + 1, INF);
    distance[1] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);
    
    while (!pq.empty())
    {
        auto [nowCost, nowNode] = pq.top();
        
        if (nowCost > distance[nowNode])
        {
            pq.pop();
            continue;
        }
        
        for (auto [nextCost, nextNode] : edges[nowNode])
        {
            if (nowCost + nextCost < distance[nextNode])
            {
                distance[nextNode] = nowCost + nextCost;
                pq.emplace(distance[nextNode], nextNode);
            }
        }
        
        pq.pop();
    }
    
    return count_if(next(distance.begin()), distance.end(), [K](int d) { return d <= K; });
}