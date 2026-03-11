#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices)
{
    stack<pair<int, int>> before;
    vector<int> answer(prices.size());
    
    for (int i = 0; i < prices.size(); i++)
    {
        while (!before.empty() && before.top().first > prices[i])
        {
            answer[before.top().second] = i - before.top().second;
            before.pop();
        }
        
        before.push({prices[i], i});
    }
    
    while (!before.empty())
    {
        answer[before.top().second] = prices.size() - before.top().second - 1;
        before.pop();
    }
    
    return answer;
}

/*
vector<int> solution(vector<int> prices)
{
    multimap<int, int> before;
    vector<int> answer(prices.size());
    
    for (int i = 0; i < prices.size(); i++)
    {
        for (auto it = before.lower_bound(prices[i] + 1); it != before.end(); it++)
            answer[it->second] = i - it->second;
        
        before.erase(before.lower_bound(prices[i] + 1), before.end());
        before.insert({prices[i], i});
    }
    
    for (auto x : before)
        answer[x.second] = prices.size() - x.second - 1;
    
    return answer;
}
*/