#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 0;

    string str_a = to_string(a);
    string str_b = to_string(b);

    string str_a_b = str_a + str_b;
    string str_b_a = str_b + str_a;

    int a_b = stoi(str_a_b);
    int b_a = stoi(str_b_a);

    answer = max(a_b, b_a);

    return answer;
}

int main()
{
    cout << solution(9, 91) << ' ' << solution(89, 8);
}