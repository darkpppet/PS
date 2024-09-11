#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long powMod(long long a, long long b, long long y)
{
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;

    if (b == 0)
        return 1;
    if (b == 1)
        return a % y;

    if (y == 1)
        return 0;

    long long z = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
            z = (a * z) % y;
        a = (a * a) % y;
        b >>= 1;
    }
    return z;
}

int reverseBit(int bit, int len)
{
    int result = 0;

    for (int i = 0; i < len; i++)
    {
        result <<= 1;
        result |= 1 & bit;
        bit >>= 1;
    }

    return result;
}

long long p = 998'244'353LL;
long long originW = 15'311'432LL;
long long originWInverse = 469'870'224LL;
long long two_b = 1 << 23;

void fft(vector<long long> &seq)
{
    int n = seq.size();
    int l = log2(n);
    for (int i = 1; i < n - 1; i++)
    {
        int reversed = reverseBit(i, l);

        if (reversed > i)
            swap(seq[i], seq[reversed]);
    }

    for (int length = 2; length <= n; length *= 2)
    {
        long long w = powMod(originW, two_b / length, p);
        long long nowW = 1;
        for (int i = 0; i < length / 2; i++)
        {
            for (int offset = 0; offset <= n - length; offset += length)
            {
                long long e = seq[offset + i];
                long long o = (seq[offset + i + length / 2] * nowW) % p;
                seq[offset + i] = (e + o) % p;
                seq[offset + i + length / 2] = (e - o) % p;
                seq[offset + i + length / 2] += seq[offset + i + length / 2] < 0 ? p : 0;
            }

            nowW *= w;
            nowW %= p;
        }
    }
}

void ifft(vector<long long> &seq)
{
    int n = seq.size();
    int l = log2(n);
    for (int i = 1; i < n - 1; i++)
    {
        int reversed = reverseBit(i, l);

        if (reversed > i)
            swap(seq[i], seq[reversed]);
    }

    for (int length = 2; length <= n; length *= 2)
    {
        long long wInverse = powMod(originWInverse, two_b / length, p);
        long long nowW = 1;
        for (int i = 0; i < length / 2; i++)
        {
            for (int offset = 0; offset <= n - length; offset += length)
            {
                long long e = seq[offset + i];
                long long o = (seq[offset + i + length / 2] * nowW) % p;
                seq[offset + i] = (e + o) % p;
                seq[offset + i + length / 2] = (e - o) % p;
                seq[offset + i + length / 2] += seq[offset + i + length / 2] < 0 ? p : 0;
            }

            nowW *= wInverse;
            nowW %= p;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> a(1<<21);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a[temp] = 1;
    }

    fft(a);

    for (int i = 0; i < 1 << 21; i++)
        a[i] = powMod(a[i], k, p);

    ifft(a);

    vector<int> ans;
    for (int i = 0; i < 1 << 21; i++)
        if ((a[i] * -476LL) % p != 0)
            ans.push_back(i);

    for (auto sum: ans)
        cout << sum << " ";
}
