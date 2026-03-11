#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    const char kc = k + '0';
    
    for (int ii = i; ii <= j; ii++)
    {
        string s = to_string(ii);
        answer += count (s.begin(), s.end(), kc);
    }
    
    return answer;
}