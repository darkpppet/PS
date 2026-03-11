#include <string>
#include <vector>
#include <bitset>
#include <array>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    array<int, 10> count {};
    bitset<100> memo;
    
    for (int p : priorities)
        count[p]++;
    
    int answer = 0, pointer = 0;
    for (int i = 9; i >= 1; i--)
    {
        while (count[i] > 0)
        {
            if (!memo[pointer] && priorities[pointer] == i)
            {
                memo.set(pointer);
                count[i]--;
                answer++;
                
                if (pointer == location)
                    return answer;
            }
            pointer = (pointer + 1) % priorities.size();
        }
    }
}