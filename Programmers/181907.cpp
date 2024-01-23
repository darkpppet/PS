#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n)
{
    string answer = "";

    answer = my_string.substr(0, n);

    return answer;
}

int main()
{
    cout << solution("ProgrammerS123", 11);
}