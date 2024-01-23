#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> left(num_list.begin(), num_list.begin() + n);
    vector<int> right(num_list.begin() + n, num_list.end());

    for (int i : left)
    {
        right.push_back(i);
    }

    return right;
}

int main()
{
    auto result = solution(vector<int>{5, 2, 1, 7, 5}, 3);
    for (auto i : result)
    {
        cout << i << ' ';
    }
}