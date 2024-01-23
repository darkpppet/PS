#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString)
{
    vector<string> answer;

    string temp;
    for (char c : myString)
    {
        if (c == 'x')
        {
            if (!temp.empty())
            {
                answer.push_back(temp);
                temp = string();
            }
        }
        else
        {
            temp += c;
        }
    }

    if (!temp.empty())
    {
        answer.push_back(temp);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    auto result = solution("zxcxbxaxxxxxxx");
    for (auto s : result)
    {
        cout << "\"" << s << "\" ";
    }
}