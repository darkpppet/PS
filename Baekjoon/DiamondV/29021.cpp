#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr long long powMod(long long a, long long b, const long long y)
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

constexpr int reverseBit(int bit, const int len)
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

constexpr long long p = 998'244'353LL;
constexpr long long originW = 15'311'432LL;
constexpr long long originWInverse = 469'870'224LL;
constexpr long long two_b = 1 << 23;

void ntt_internal(vector<long long>& seq, const long long inputW)
{
    const int n = static_cast<int>(seq.size());
    const int l = static_cast<int>(log2(n));
    for (int i = 1; i < n - 1; i++)
    {
        const int reversed = reverseBit(i, l);
        if (reversed > i)
            swap(seq[i], seq[reversed]);
    }

    for (int length = 2; length <= n; length *= 2)
    {
        const long long w = powMod(inputW, two_b / length, p);
        long long nowW = 1;
        for (int i = 0; i < length / 2; i++)
        {
            for (int offset = 0; offset <= n - length; offset += length)
            {
                const long long e = seq[offset + i];
                const long long o = (seq[offset + i + length / 2] * nowW) % p;
                seq[offset + i] = (e + o) % p;
                seq[offset + i + length / 2] = (e - o) % p;
                seq[offset + i + length / 2] += seq[offset + i + length / 2] < 0 ? p : 0;
            }

            nowW *= w;
            nowW %= p;
        }
    }
}

void ntt(vector<long long>& seq)
{
    ntt_internal(seq, originW);
}

void intt(vector<long long>& seq)
{
    ntt_internal(seq, originWInverse);
}

constexpr long long getInverseP(const long long kFFTSize)
{
    return powMod(kFFTSize, p - 2, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr int kFFTSize = 1 << 20;
    constexpr long long kInverseP = getInverseP(kFFTSize);

    vector<long long> originSeq(kFFTSize);
    for (int i = 1; i <= 255; i++)
        originSeq[i] = i;
    ntt(originSeq);

    while (true)
    {
        int k, n;
        cin >> k >> n;
        if (k == 0 && n == 0)
            return 0;

        vector<long long> seq(originSeq);
        for (int i = 0; i < kFFTSize; i++)
            seq[i] = powMod(seq[i], k, p);
        intt(seq);

        cout << (seq[n] * kInverseP) % p << '\n';
    }
}
