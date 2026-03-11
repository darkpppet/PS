#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int age) {
    string answer = to_string(age);
    
    transform(answer.begin(), answer.end(), answer.begin(), [](char c) { return c - '0' + 'a'; });
    
    return answer;
}