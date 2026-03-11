#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    int num1 = numbers[0] * numbers[1];
    int num2 = numbers[numbers.size() - 2] * numbers[numbers.size() - 1];
    
    return max(num1, num2);
}