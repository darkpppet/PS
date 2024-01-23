#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int base = ceil(log2(arr.size()));
    int offset = pow(2, base) - arr.size();

    for (int i = 0; i < offset; i++)
    {
        arr.push_back(0);
    }

    return arr;
}