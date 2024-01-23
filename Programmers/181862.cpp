#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr)
{
    vector<string> answer;

    string temp;
    for (char c : myStr)
    {
        switch (c)
        {
            case 'a':
            case 'b':
            case 'c':
                if (!temp.empty())
                {
                    answer.push_back(temp);
                    temp = string();
                }
                break;
            default:
                temp += c;
        }
    }

    if (!temp.empty())
    {
        answer.push_back(temp);
    }

    if (answer.size() == 0)
    {
        answer.push_back("EMPTY");
    }

    return answer;
}

int main()
{
    auto result = solution("baconlettucetomato");
    for (auto c : result)
        cout << c << ' ';
}