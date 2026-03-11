#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int dfs(const vector<vector<int>>& children, vector<bool>& check, int node, int n, int& minDiff)
{
    check[node] = true;
    int answer = 1;
    
    for (auto child : children[node])
    {
        if (!check[child])
        {
            int temp = dfs(children, check, child, n, minDiff);
            int diff = abs(n - 2 * temp);
            minDiff = min(minDiff, diff);
            
            answer += temp;
        }
    }
    
    return answer;
}

int solution(int n, vector<vector<int>> wires)
{
    vector<vector<int>> children(n + 1);
    for (auto wire : wires)
    {
        children[wire[0]].push_back(wire[1]);
        children[wire[1]].push_back(wire[0]);
    }
    
    vector<bool> check(n + 1);
    int minDiff = 101;
    dfs(children, check, 1, n, minDiff);
    
    return minDiff;
}


/*
int dfs(const unordered_multimap<int, int>& children, int node, int n, int& minDiff)
{
    if (children.find(node) == children.end())
        return 1;
    
    auto [s, e] = children.equal_range(node);
    int count = 1;
    for (auto it = s; it != e; it++)
    {
        int child = dfs(children, it->second, n, minDiff);
        minDiff = min(minDiff, abs(n - 2 * child));

        count += child;
    }
    return count;
}

int solution(int n, vector<vector<int>> wires)
{
    unordered_multimap<int, int> children;
    {
        unordered_multimap<int, int> wiresMap;
        
        for (auto wire : wires)
        {
            wiresMap.emplace(wire[0], wire[1]);
            wiresMap.insert({ wire[1], wire[0] });
        }
        
        queue<int> temp;
        temp.push(1);
        vector<bool> check(n + 1);
        check[1] = true;
        
        while (!temp.empty())
        {
            auto i = temp.front();
            temp.pop();
            check[i] = true;
            
            auto [s, e] = wiresMap.equal_range(i);
            for (auto it = s; it != e; it++)
            {
                int count = 0;
                if (!check[it->second])
                {
                    children.insert({ i, it->second });
                    temp.push(it->second);
                    count++;
                }
            }
        }
    }
    
    int minDiff = 101;
    dfs(children, 1, n, minDiff);
    
    return minDiff;
}*/