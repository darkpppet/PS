#include <iostream>
#include <vector>
#include <algorithm>
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

constexpr int kFFTSize = 1 << 21;

void addToSeq(vector<int>& seq, const string& str, const char color)
{
    vector<complex<double>> seqC(kFFTSize);
    vector<complex<double>> seqNC(kFFTSize);
    for (int i = 0; i < str.size(); i++)
    {
        seqC[i] = str[i] == color ? 1 : 0;
        seqC[i + str.size()] = seqC[i];
        seqNC[str.size() - 1 - i] = str[i] != color ? 1 : 0;
    }

    fft(seqC);
    fft(seqNC);
    for (int i = 0; i < kFFTSize; i++)
        seqC[i] = seqC[i] * seqNC[i];
    ifft(seqC);

    for (int i = 0; i < str.size(); i++)
        seq[i] += static_cast<int>(round(seqC[str.size() - 1 + i].real() / kFFTSize));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    vector<int> seq(s.size());
    addToSeq(seq, s, 'R');
    addToSeq(seq, s, 'B');
    addToSeq(seq, s, 'Y');

    vector<int> sortedSeq(seq);
    ranges::sort(sortedSeq);
    const int craz = sortedSeq[p];

    for (int i = 1; i < seq.size(); i++)
    {
        if (seq[i] == craz)
        {
            cout << i;
            return 0;
        }
    }
}
