#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <numbers>
#include <complex>
#include <ranges>

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

void makeSeq(vector<complex<double>> &seq, const map<int, int>& nums)
{
    int sum = 0;
    for (const int value: nums | views::values)
    {
        sum += value;
        seq[sum] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr int kFFTSize = 1 << 19;

    vector<complex<double>> oSeq(kFFTSize);
    vector<complex<double>> eSeq(kFFTSize);
    {
        int n;
        cin >> n;

        map<int, int> os {{0, 0}}, es{{0, 0}};
        for (int i = 0; i < n; i++)
        {
            int o, e;
            cin >> o >> e;

            os[o] += 1;
            es[e] += 1;
        }
        makeSeq(oSeq, os);
        makeSeq(eSeq, es);
    }

    fft(oSeq);
    fft(eSeq);
    for (int i = 0; i < kFFTSize; i++)
        oSeq[i] = oSeq[i] * eSeq[i];
    ifft(oSeq);

    int count = 0;
    for (int i = 0; i < kFFTSize; i++)
    {
        const int point = static_cast<int>(round(oSeq[i].real() / kFFTSize));
        count += point > 0 ? 1 : 0;
    }

    cout << count;

    return 0;
}
