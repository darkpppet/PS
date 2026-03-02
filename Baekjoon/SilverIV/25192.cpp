#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<string> history;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s == "ENTER")
        {
            result += history.size();
            history = unordered_set<string>();
            continue;
        }

        history.insert(s);
    }
    result += history.size();

    cout << result << endl;

    return 0;
}