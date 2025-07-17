#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>
#include <complex>
#include <algorithm>

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

    string s;
    cin >> s;
    int n = s.size();

    vector<complex<double>> bSeq(2097152);
    vector<complex<double>> aSeq(2097152);

    for (int i = 0; i < s.size(); i++)
    {
        bSeq[i] = s[i] == 'B' ? 1 : 0;
        aSeq[n - i - 1] = s[i] == 'A' ? 1 : 0;
    }

    fft(bSeq);
    fft(aSeq);

    vector<complex<double>> resultSeq(2097152);
    for (int i = 0; i < 2097152; i++)
        resultSeq[i] = bSeq[i] * aSeq[i];

    ifft(resultSeq);

    for (int i = n - 2; i >= 0; i--)
        cout << static_cast<int>(round(resultSeq[i].real() / 2097152)) << '\n';
}
