#include <iostream>
#include <ranges>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> frequencies;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;

        if (word.size() < m)
            continue;

        frequencies[word]++;
    }

    vector<string> words;
    ranges::transform(frequencies, back_inserter(words), [](const auto& f) { return f.first; });
    ranges::sort(words, [&frequencies](const string& a, const string& b)
    {
        if (frequencies[a] != frequencies[b])
            return frequencies[a] > frequencies[b];

        if (a.size() != b.size())
            return a.size() > b.size();

        return a < b;
    });

    for (const string& word : words)
        cout << word << '\n';

    return 0;
}