#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    unordered_set<int> sumset;
    for (int i = 0 ; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
            sumset.insert(numbers[i] + numbers[j]);
    }
    
    vector<int> answer(sumset.begin(), sumset.end());
    sort(answer.begin(), answer.end());
    return answer;
}