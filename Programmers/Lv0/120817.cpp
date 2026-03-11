#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    return (double)accumulate(numbers.begin(), numbers.end(), 0) / numbers.size();
}