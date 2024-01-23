#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> **relationship;
unordered_set<int> *before;

int calc_number(int a, int b)
{
    if (a == b)
    {
        return 1;
    }

    int result = 1;
    int index = a;

    while (true)
    {
        before = relationship[index];
        for (auto human = before->find(b); human != before->end(); human++)
        {
            return result;
        }
        result++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    relationship = new unordered_set<int>*[n + 1];

    for (int i = 1; i < n + 1; i++)
    {
        relationship[i] = new unordered_set<int>;
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        relationship[a]->insert(b);
        relationship[b]->insert(a);
    }

    auto number = new int[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        int temp = 0;
        for (int j = 1; j < n + 1; j++)
        {
            temp += calc_number(a, b);
        }
        number[i] = temp;
    }

    int minindex = 1;
    int min = n * n;

    for (int i = 1; i < n + 1; i++)
    {
        if (number[i] < min)
        {
            min = number[i];
            minindex = i;
        }
    }

    cout << minindex;

    delete number;
    delete []relationship;

    return 0;
}