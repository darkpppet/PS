#include <string>
#include <vector>

using namespace std;

long long solution(string numbers)
{
    const vector<string> nums
    {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    
    for (int i = 0; i <= 9; i++)
    {
        const string num = nums[i];
        auto pos = numbers.find(num);
        while (pos != string::npos)
        {
            numbers.replace(pos, num.size(), to_string(i));
            pos = numbers.find(num);
        }
    }
    
    return stoll(numbers);
}