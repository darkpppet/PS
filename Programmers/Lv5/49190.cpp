#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <utility>
#include <numeric>
#include <iostream>

using namespace std;

constexpr long long pairToLL(pair<int, int> p)
{
    constexpr long long FirstFactor = 200'002;
    return static_cast<long long>(p.first) * FirstFactor + static_cast<long long>(p.second);
}

constexpr long long pairToLL(int first, int second)
{
    constexpr long long FirstFactor = 200'002;
    return static_cast<long long>(first) * FirstFactor + static_cast<long long>(second);
}

constexpr array<pair<int, int>, 8> directions
{{
    { 0, 2 }, { 2, 2 }, { 2, 0 }, { 2, -2 },
    { 0, -2 }, { -2, -2 }, { -2, 0 }, { -2, 2 }
}};

int solution(vector<int> arrows)
{
    unordered_map<long long, unordered_set<long long>> graph;
    unordered_set<long long> nodes;
    
    auto now = pairToLL(0, 0);
    for (auto a : arrows)
    {
        nodes.insert(now);
        
        auto next = now + pairToLL(directions[a]);
        if (a % 2 == 0)
        {
            graph[now].insert(next);
            graph[next].insert(now);
        }
        else
        {
            auto mid = (now + next) / 2;
            nodes.insert(mid);
            graph[now].insert(mid);
            graph[mid].insert(now);
            graph[mid].insert(next);
            graph[next].insert(mid);
        }
        
        now = next;
    }
    nodes.insert(now);
    
    int e = accumulate(graph.begin(), graph.end(), 0, [](auto a, auto b) { return a + b.second.size(); });
    
    return e / 2  - nodes.size() + 1;
}