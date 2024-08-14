#include <iostream>
#include <utility>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int fruits[n];
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }

    int start = 0;
    int end = 1;
    pair<int, int> fruit1 = make_pair(fruits[0], 1);
    pair<int, int> fruit2 = make_pair(0, 0);

    int maxFruit = 1;

    while (start < n && end <= n)
    {
        maxFruit = max(end - start, maxFruit);

        if (fruits[end] == fruit1.first)
        {
            fruit1.second++;
            end++;
            continue;
        }

        if (fruits[end] == fruit2.first)
        {
            fruit2.second++;
            end++;
            continue;
        }

        if (fruit1.second == 0)
        {
            fruit1 = make_pair(fruits[end], 1);
            end++;
            continue;
        }

        if (fruit2.second == 0)
        {
            fruit2 = make_pair(fruits[end], 1);
            end++;
            continue;
        }

        if (fruits[start] == fruit1.first)
        {
            fruit1.second--;
            start++;
            continue;
        }

        if (fruits[start] == fruit2.first)
        {
            fruit2.second--;
            start++;
            continue;
        }
    }

    cout << maxFruit;
}
