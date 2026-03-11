#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int n : numbers)
        answer.push_back(2 * n);
    
    return answer;
}