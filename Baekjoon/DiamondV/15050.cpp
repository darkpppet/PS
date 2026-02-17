#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>
#include <complex>

using namespace std;

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

void fft(vector<complex<double>> &seq)
{
    int n = seq.size();
    int p = log2(n);
    for (int i = 0; i < n; i++)
    {
        int reversed = reverseBit(i, p);

        if (reversed > i)
            swap(seq[i], seq[reversed]);
    }

    for (int length = 2; length <= n; length *= 2)
    {
        complex<double> w(cos(2*numbers::pi/length), -sin(2*numbers::pi/length));
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

void ifft(vector<complex<double>> &seq)
{
    int n = seq.size();
    int p = log2(n);
    for (int i = 0; i < n; i++)
    {
        int reversed = reverseBit(i, p);

        if (reversed > i)
            swap(seq[i], seq[reversed]);
    }

    for (int length = 2; length <= n; length *= 2)
    {
        complex<double> w(cos(2*numbers::pi/length), sin(2*numbers::pi/length));
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr int kFftSize = 1 << 23;
    constexpr int kM = kFftSize / 2;

    string s;
    cin >> s;

    vector<complex<double>> seq1(kFftSize);
    vector<complex<double>> seq2(kFftSize);
    seq1[0] = 1;
    seq2[kM] = 1;
    int sum = 0;
    for (const char c : s)
    {
        sum += c - 'a' + 1;
        seq1[sum] = 1;
        seq2[kM - sum] = 1;
    }

    fft(seq1);
    fft(seq2);

    vector<complex<double>> resultSeq(kFftSize);
    for (int i = 0; i < kFftSize; i++)
        resultSeq[i] = seq1[i] * seq2[i];

    ifft(resultSeq);

    int result = 0;
    for (int i = kM + 1; i < kFftSize; i++)
    {
        if (static_cast<int>(round(resultSeq[i].real() / kFftSize)) != 0)
            result++;
    }

    cout << result;
    return 0;
}
