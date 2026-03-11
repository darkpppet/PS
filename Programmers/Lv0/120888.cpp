#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string) {
    unordered_set<char> memo;
    string answer = "";
    
    for (char c : my_string)
    {
        if (memo.find(c) == memo.end())
        {
            answer += c;
            memo.insert(c);
        }
    }
    
    return answer;
}