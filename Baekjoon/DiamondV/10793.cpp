#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numbers>
#include <complex>

using namespace std;

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

void fft_internal(vector<complex<double>> &seq, const bool isInverse)
{
    const int n = static_cast<int>(seq.size());
    const int p = static_cast<int>(log2(n));
    for (int i = 0; i < seq.size(); i++)
    {
        const int reversed = reverseBit(i, p);
        if (reversed > i)
            swap(seq[i], seq[reversed]);
    }

    for (int length = 2; length <= seq.size(); length *= 2)
    {
        const double re = cos(2 * numbers::pi / length);
        const double im = sin(2 * numbers::pi / length) * (isInverse ? -1 : 1);
        const complex<double> w(re, im);

        complex<double> nowW(1);
        for (int i = 0; i < length / 2; i++)
        {
            for (int offset = 0; offset <= n - length; offset += length)
            {
                complex<double> e = seq[offset + i];
                complex<double> o = seq[offset + i + length / 2] * nowW;
                seq[offset + i] = e + o;
                seq[offset + i + length / 2] = e - o;
            }
            nowW *= w;
        }
    }
}

void fft(vector<complex<double>> &seq)
{
    fft_internal(seq, false);
}

void ifft(vector<complex<double>> &seq)
{
    fft_internal(seq, true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr int kMaxA = 500'000;
    constexpr int kFFTSize = 1 << 20;

    vector<complex<double>> seqOrigin(kFFTSize);
    for (int i = 1; i <= kMaxA; i++)
    {
        for (int j = i; j <= kMaxA; j += i)
            seqOrigin[j] += 1;
    }

    fft(seqOrigin);
    for (int i = 0; i < kFFTSize; i++)
        seqOrigin[i] *= seqOrigin[i];
    ifft(seqOrigin);

    vector<int> seq;
    seq.reserve(kFFTSize);
    ranges::transform(seqOrigin, back_inserter(seq), [](const complex<double> x)
    {
        return static_cast<int>(round(x.real() / kFFTSize));
    });

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int alo, ahi;
        cin >> alo >> ahi;

        int a = alo, w = seq[alo];
        for (int j = alo + 1; j <= ahi; j++)
        {
            if (seq[j] > w)
            {
                a = j;
                w = seq[j];
            }
        }

        cout << a << ' ' << w << '\n';
    }

    return 0;
}
