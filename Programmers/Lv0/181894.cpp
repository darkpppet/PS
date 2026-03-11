#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    auto first = find(arr.begin(), arr.end(), 2);

    if (first == arr.end())
    {
        return { -1 };
    }

    auto second = first;
    auto next = second;
    while (next != arr.end())
    {
        second = next;
        next = find(second + 1, arr.end(), 2);
    }

    return vector<int>(first, second + 1);
}