#include <string>

using namespace std;

bool solution(string s)
{
    int tower = 0;
    for (char c : s)
    {
        if (c == 'p' || c == 'P')
            tower++;
        else if (c == 'y' || c == 'Y')
            tower--;
    }
    return !tower;
}