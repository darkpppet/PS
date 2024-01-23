#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    string answer = my_string;

    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == alp[0])
        {
            answer[i] = toupper(alp[0]);
        }
    }

    return answer;
}

int main()
{
    cout << solution("programmers", "p");
}