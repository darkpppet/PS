#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<string> dancers { "ChongChong" };

    for (int i = 0; i < n; i++)
    {
        string name1, name2;
        cin >> name1 >> name2;

        if (dancers.contains(name1))
            dancers.insert(name2);
        else if (dancers.contains(name2))
            dancers.insert(name1);
    }

    cout << dancers.size() << endl;

    return 0;
}