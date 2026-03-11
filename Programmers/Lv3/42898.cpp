#include <string>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <array>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    array<bitset<101>, 101> puddleTable;
    for (auto puddle : puddles)
        puddleTable[puddle[0]].set(puddle[1]);
    
    vector<int> before(n + 1);
    before[1] = 1;
    
    for (int i = 1; i <= m; i++)
    {
        vector<int> now(n + 1);
        for (int j = 1; j <= n; j++)
        {
            if (!puddleTable[i].test(j))
                now[j] = (now[j - 1] + before[j]) % 1'000'000'007;
        }
        before = move(now);
    }
    
    return before[n];
}