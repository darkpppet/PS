#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (char c: my_string)
    {
        if (isdigit(c))
        {
            answer += c - '0';
        }
    }
    
    return answer;
}