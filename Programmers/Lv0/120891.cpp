#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    for (char c : to_string(order))
    {
        if (c == '3' || c == '6' || c == '9')
        {
            answer++;
        }
    }
    
    
    return answer;
}