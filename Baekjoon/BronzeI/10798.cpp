#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<string, 5> words;

    for (int i = 0; i < 5; i++)
        cin >> words[i];

    string result;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i >= words[j].size())
                continue;

            result += words[j][i];
        }
    }

    cout << result;
    return 0;
}