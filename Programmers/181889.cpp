#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> answer(num_list.begin(), num_list.begin() + n);
    return answer;
}

int main()
{
    auto input = vector<int>{2, 1, 6};
    for (int i : solution(input, 1))
    {
        cout << i << ' ';
    }
}