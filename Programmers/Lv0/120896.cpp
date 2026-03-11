#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> memo(26);
    string answer = "";
    
    for (char c: s)
    {
        memo[c - 'a']++;
    }
    
    for (int i = 0; i < memo.size(); i++)
    {
        if (memo[i] == 1)
        {
            answer += i + 'a';
        }
    }
    
    return answer;
}