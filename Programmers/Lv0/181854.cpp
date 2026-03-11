#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n)
{
    int i = 0;

    if (arr.size() % 2 == 0)
    {
        i = 1;
    }

    for (; i < arr.size(); i += 2)
    {
        arr[i] += n;
    }

    return arr;
}