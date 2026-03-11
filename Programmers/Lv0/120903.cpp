#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for (string s : s1)
    {
        if (auto pos = find(s2.begin(), s2.end(), s); pos != end(s2))
        {
            answer++;
        }
    }
    
    return answer;
}