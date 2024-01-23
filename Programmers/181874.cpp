#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char c) -> char
    {
        if (c == 'a' || c == 'A')
        {
            return toupper(c);
        }
        else
        {
            return tolower(c);
        }
    });

    return myString;
}