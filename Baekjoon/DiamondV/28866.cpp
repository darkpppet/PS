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

constexpr long long getTwoB(long long pn)
{
    long long result = 1;
    pn -= 1;
    while (pn % 2 == 0)
    {
        pn /= 2;
        result *= 2;
    }
    return result;
}

constexpr long long p = 786'433;
constexpr long long originW = 1'000;
constexpr long long originWInverse = powMod(originW, p - 2, p);
constexpr long long two_b = getTwoB(p);

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

constexpr int kFFTSize = 1 << 17;
constexpr long long kInverseP = getInverseP(kFFTSize);
constexpr int maxIndex = 50000;

void polyTrunc(vector<long long>& seq)
{
    for (int i = 0; i <= maxIndex; i++)
        seq[i] = (seq[i] * kInverseP) % p;
    for (int i = maxIndex + 1; i < kFFTSize; i++)
        seq[i] = 0;
}

void polyMultiply(vector<long long>& seq, vector<long long> seq2)
{
    ntt(seq);
    ntt(seq2);
    for (int i = 0; i < kFFTSize; i++)
        seq[i] = (seq[i] * seq2[i]) % p;
    intt(seq);

    polyTrunc(seq);
}

void polySquare(vector<long long>& seq)
{
    ntt(seq);
    for (int i = 0; i < kFFTSize; i++)
        seq[i] = (seq[i] * seq[i]) % p;
    intt(seq);

    polyTrunc(seq);
}

void polyPow(vector<long long>& seq, int k)
{
    vector<long long> temp(kFFTSize);
    temp[0] = 1;

    while (k > 0)
    {
        if (k & 1)
            polyMultiply(temp, seq);
        polySquare(seq);
        k >>= 1;
    }

    swap(temp, seq);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<long long> seq(kFFTSize);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        seq[temp] += 1;
    }

    polyPow(seq, k);

    seq[0] = 0;
    for (int i = 1; i <= maxIndex; i++)
        seq[i] = (seq[i - 1] + seq[i]) % p;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << (seq[r] - seq[l - 1] + p) % p << '\n';
    }
}
