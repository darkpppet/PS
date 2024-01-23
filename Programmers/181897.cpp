#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
    switch (n)
    {
        case 1:
            return vector<int>(num_list.begin(), num_list.begin() + slicer[1] + 1);
        case 2:
            return vector<int>(num_list.begin() + slicer[0], num_list.end());
        case 3:
            return vector<int>(num_list.begin() + slicer[0], num_list.begin() + slicer[1] + 1);
        case 4:
            vector<int> answer;
            for (int i = slicer[0]; i <= slicer[1]; i += slicer[2])
            {
                answer.push_back(num_list[i]);
            }
            return answer;
    }
}

int main()
{
    auto result = solution(4, {1, 5, 2}, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    for (auto i : result)
        cout << i << ' ';
}