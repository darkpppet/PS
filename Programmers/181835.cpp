#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    function<int(int)> lambda;
    if (k % 2 != 0)
    {
        lambda = [=](int i) -> int { return i * k; };
    }
    else
    {
        lambda = [=](int i) -> int { return i + k; };
    }

    transform(arr.begin(), arr.end(), arr.begin(), lambda);
    return arr;
}