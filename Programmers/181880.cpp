#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc(int num)
{
    int count = 0;
    while (num > 1)
    {
        num /= 2;
        count++;
    }
    return count;
}

int solution(vector<int> num_list)
{
    int count = 0;
    for (int i : num_list)
    {
        count += calc(i);
    }
    return count;
}

int main()
{
    cout << solution({12, 4, 15, 1, 14});
}