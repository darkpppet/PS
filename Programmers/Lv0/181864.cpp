#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat)
{
    transform(myString.begin(), myString.end(), myString.begin(), [](char c) -> char
    {
        if (c == 'A')
        {
            return 'B';
        }
        return 'A';
    });

    if (myString.find(pat) != string::npos)
    {
        return 1;
    }
    return 0;
}