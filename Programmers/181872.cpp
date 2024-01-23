#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString, string pat)
{
    reverse(myString.begin(), myString.end());
    reverse(pat.begin(), pat.end());

    auto index = myString.find(pat);

    string answer = myString.substr(index);
    reverse(answer.begin(), answer.end());

    return answer;
}