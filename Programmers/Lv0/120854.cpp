#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer(strlist.size());
    transform(strlist.cbegin(), strlist.cend(), answer.begin(), [](string s)
    {
        return s.size();
    });
    return answer;
}