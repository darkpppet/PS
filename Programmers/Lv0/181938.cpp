#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 0;

    string str_a = to_string(a);
    string str_b = to_string(b);

    string str_a_b = str_a + str_b;
    int a_b = stoi(str_a_b);

    answer = max(a_b, 2 * a * b);

    return answer;
}