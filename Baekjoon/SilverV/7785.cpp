#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<string> employeesInCompany;
    for (int i = 0; i < n; i++)
    {
        string name, log;
        cin >> name >> log;

        if (log == "enter")
            employeesInCompany.insert(name);
        else
            employeesInCompany.erase(name);
    }

    vector<string> names(employeesInCompany.begin(), employeesInCompany.end());
    ranges::sort(names, ranges::greater());

    for (const string& name : names)
        cout << name << '\n';

    return 0;
}