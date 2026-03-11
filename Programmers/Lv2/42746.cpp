#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

string solution(vector<int> numbers)
{
    vector<string> numStrings;
    transform(numbers.begin(), numbers.end(), back_inserter(numStrings), static_cast<string(*)(int)>(to_string));
    
    sort(numStrings.begin(), numStrings.end(), [](const string& s1, const string& s2)
         {
             return s1 + s2 > s2 + s1;
         });
    
    string answer;
    for (auto s : numStrings)
        answer += s;
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}