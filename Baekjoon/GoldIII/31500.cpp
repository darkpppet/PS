#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr long long seqSize = 7000;

    int n;
    cin >> n;

    bool isMinus = false;

    vector<long long> a(seqSize);
    vector<long long> b(seqSize);

    string s;
    cin >> s;
    int offset = 0;
    if (s[0] == '~')
    {
        isMinus = !isMinus;
        offset = 1;
    }
    for (int i = s.size() - 1; i >= offset; i--)
        a[s.size() - i - 1] = s[i] - 33;

    cin >> s;
    offset = 0;
    if (s[0] == '~')
    {
        isMinus = !isMinus;
        offset = 1;
    }
    for (int i = s.size() - 1; i >= offset; i--)
        b[s.size() - i - 1] = s[i] - 33;

    vector<long long> c(seqSize);

    for (int i = 0; i < seqSize / 2; i++)
    {
        for (int j = 0; j < seqSize / 2; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    s = "";
    if (n > 0)
    {
        long long carry = 0;
        for (int i = 0; i < seqSize; i++)
        {
            long long temp = carry + c[i];

            carry = temp / n;
            temp = temp % n;

            s += static_cast<char>(temp + 33);
        }
    }
    else
    {
        long long carry = 0;
        for (int i = 0; i < seqSize; i++)
        {
            long long temp = carry + c[i];

            carry = temp / n;
            long long r = temp % n;
            temp = r >= 0 ? r : r - n;
            carry += r >= 0 ? 0 : 1;

            s += static_cast<char>(temp + 33);
        }
    }
    for (auto i = s.end() - 1; i >= s.begin(); i--)
    {
        if (*i != '!')
        {
            s = string(s.begin(), i + 1);
            break;
        }

        if (i == s.begin())
        {
            s = "!";
            isMinus = false;
        }
    }
    s += isMinus ? "~" : "";
    reverse(s.begin(), s.end());

    cout << s;
}
