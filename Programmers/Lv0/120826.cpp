#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    while (true)
    {
        if (auto pos = my_string.find(letter); pos != string::npos)
            my_string.replace(pos, 1, "");
        else
            break;
    }
    return my_string;
}