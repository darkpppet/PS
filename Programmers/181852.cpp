#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer = num_list;
    sort(answer.begin(), answer.end());
    answer = vector<int>(answer.begin()+5, answer.end());

    return answer;
}

int main()
{
    auto input = vector<int>{12, 4, 15, 46, 38, 1, 14, 56, 32, 10};
    auto result = solution(input);

    for (int i : result)
    {
        cout << i << " ";
    }

}