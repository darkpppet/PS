#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    for (int element : delete_list)
    {
        auto index = find(arr.begin(), arr.end(), element);

        if (index != arr.end())
        {
            arr.erase(index);
        }
    }

    return arr;
}