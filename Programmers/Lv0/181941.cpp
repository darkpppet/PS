#include <numeric>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr)
{
    string answer = accumulate(arr.begin(), arr.end(), string());
    return answer;
}
