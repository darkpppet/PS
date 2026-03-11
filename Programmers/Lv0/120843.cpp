#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k)
{
    const int index = (2 * (k - 1)) % (numbers.size());
    
    return numbers[index];
}