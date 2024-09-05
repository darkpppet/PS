#include <iostream>
#include <vector>
#include <cmath>
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
        complex<double> w(cos(2*M_PI/length), -sin(2*M_PI/length));
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
        complex<double> w(cos(2*M_PI/length), sin(2*M_PI/length));
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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<complex<double>> seq(2097152);
    complex<double> complex1(1);
    seq[0] = complex1;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        seq[k] = complex1;
    }

    fft(seq);

    for (int i = 0; i < 2097152; i++)
        seq[i] *= seq[i];

    ifft(seq);

    int m;
    cin >> m;
    long long result = 0;
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        if (round(seq[d].real() / 2097152) > 0)
            result++;
    }

    cout << result;
}
