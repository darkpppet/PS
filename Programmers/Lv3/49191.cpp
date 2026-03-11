#include <vector>
#include <queue>
#include <bitset>
#include <iostream>

using namespace std;

int find(int i, const vector<vector<int>>& vec)
{
    int counter = 0;
    bitset<101> check;
    check.set(i);
    queue<int> next;
    next.push(i);

    while (!next.empty())
    {
        auto temp = next.front();
        for (auto node : vec[temp])
        {
            if (!check.test(node))
            {
                counter++;
                check.set(node);
                next.push(node);
            }
        }
        next.pop();
    }

    return counter;
};

int solution(int n, vector<vector<int>> results)
{
    vector<vector<int>> win(n + 1);
    vector<vector<int>> lose(n + 1);
    for (auto r : results)
    {
        win[r[0]].push_back(r[1]);
        lose[r[1]].push_back(r[0]);
    }
    
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int winnerCount = find(i, lose);
        int loserCount = find(i, win);
        
        if (winnerCount + loserCount == n - 1)
            count++;
    }
    
    return count;
}