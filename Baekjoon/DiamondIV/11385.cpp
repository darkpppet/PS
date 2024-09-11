#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long multiMod(long long a, long long b, long long y)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return a % y;

    long long temp = multiMod(a, b / 2, y);
    temp += temp;
    temp %= y;

    if (b % 2 == 0)
        return temp;
    else
        return (temp + a) % y;
}

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

long long p, originW, originWInverse, two_b;

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

    int n, m;
    cin >> n >> m;

    vector<long long> a1(2097152);
    vector<long long> a2(2097152);
    for (int i = 0; i <= n; i++)
    {
        cin >> a1[i];
        a2[i] = a1[i];
    }

    vector<long long> b1(2097152);
    vector<long long> b2(2097152);
    for (int i = 0; i <= m; i++)
    {
        cin >> b1[i];
        b2[i] = b1[i];
    }

    p = 2483027969LL;
    originW = 870726350LL;
    originWInverse = 1604034639LL;
    two_b = 1 << 26;

    fft(a1);
    fft(b1);

    vector<long long> c1(2097152);
    for (int i = 0; i < 2097152; i++)
        c1[i] = (a1[i] * b1[i]) % p;

    ifft(c1);

    p = 998244353LL;
    originW = 15311432LL;
    originWInverse = 469870224LL;
    two_b = 1 << 23;

    fft(a2);
    fft(b2);

    vector<long long> c2(2097152);
    for (int i = 0; i < 2097152; i++)
        c2[i] = (a2[i] * b2[i]) % p;

    ifft(c2);

    long long result = 0;
    for (int i = 0; i <= n + m; i++)
    {
        c1[i] = (c1[i] * -1184LL) % 2483027969LL;
        c1[i] += c1[i] < 0 ? 2483027969LL : 0;
        c2[i] = (c2[i] * -476LL) % 998244353LL;
        c2[i] += c2[i] < 0 ? 998244353LL : 0;

        long long r1 = multiMod(2254608207271893145LL, c1[i], 2478668648395309057LL);
        long long r2 = multiMod(224060441123415913LL, c2[i], 2478668648395309057LL);
        long long temp = (r1 + r2) % 2478668648395309057LL;

        result ^= temp;
    }

    cout << result;
}
