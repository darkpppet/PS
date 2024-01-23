#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;

    string str_even = "";
    string str_odd = "";

    for (const int i : num_list)
    {
        if (i % 2 == 0)
        {
            str_even += to_string(i);
        }
        else
        {
            str_odd += to_string(i);
        }
    }

    answer = stoi(str_even) + stoi(str_odd);

    return answer;
}