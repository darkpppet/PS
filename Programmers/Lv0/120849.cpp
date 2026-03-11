#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    int index = 0;
    
    while (index < my_string.size())
    {
        char c = my_string[index];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            my_string.replace(index, 1, "");
        }
        else
        {
            index++;
        }
    }
    
    return my_string;
}