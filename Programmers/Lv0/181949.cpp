#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    string result = "";

    char offset = 'A' - 'a';

    for (char c : str)
    {
        if (isupper(c))
        {
            result += tolower(c);
        }

        if (islower(c))
        {
            result += toupper(c);
        }
    }

    cout << result << endl;

    return 0;
}