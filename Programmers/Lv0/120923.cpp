#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer(num);
    
    int mid = ceil(static_cast<double>(total) / num);
    
    for (int i = 0; i < num; i++)
    {
        answer[i] = mid - num / 2 + i;
    }
    
    return answer;
}