#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food)
{
    string answer;
    for (int i = 1; i < food.size(); i++)
        answer += string(food[i] / 2, i + '0');
    answer += '0';
    for (int i = food.size() - 1; i >= 1; i--)
        answer += string(food[i] / 2, i + '0');

    return answer;
}