#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
    string answer = my_string.replace(s, overwrite_string.length(), overwrite_string);

    return answer;
}

int main(void)
{
    string answer = solution("He11oWor1d", "lloWorl", 2);
    cout << answer;
}