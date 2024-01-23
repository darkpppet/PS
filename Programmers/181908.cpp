#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix)
{
    int answer = 0;

    if (my_string.size() < is_suffix.size())
    {
        return 0;
    }

    for (int i = 0; i < is_suffix.size(); i++)
    {
        if (*(my_string.end() - i - 1) != *(is_suffix.end() - i - 1))
        {
            return 0;
        }
    }

    return 1;
}