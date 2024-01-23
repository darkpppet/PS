#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string binomial)
{
    int answer = 0;

    vector<string> split;
    string temp = "";
    for (char c : binomial)
    {
        if (c == ' ')
        {
            split.push_back(temp);
            temp = "";
        }
        else
        {
            temp += c;
        }
    }

    answer = stoi(split[0]);
    switch (split[1][0])
    {
        case '+':
            answer += stoi(temp);
            break;
        case '-':
            answer -= stoi(temp);
            break;
        case '*':
            answer *= stoi(temp);
            break;
    }

    return answer;
}

int main()
{
    cout << solution("43 + 12");
}