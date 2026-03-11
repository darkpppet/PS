#include <bitset>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    bitset<10> check;
    for (int n : numbers)
        check.set(n);
    
    int answer = 0;
    for (int i = 0; i <= 9; i++)
        answer += check.test(i) ? 0 : i;
    
    return answer;
}