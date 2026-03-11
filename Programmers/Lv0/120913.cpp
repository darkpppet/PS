#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n)
{
    vector<string> answer;
    
    for (auto i = my_str.begin(); i < my_str.end(); i += n)
    {
        auto e = i + n < my_str.end() ? i + n : my_str.end();
        answer.emplace_back(i, e);
    }
    
    return answer;
}