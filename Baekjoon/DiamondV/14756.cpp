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

    int n, l, m;
    long long w;
    cin >> n >> l >> m >> w;

    vector<vector<complex<double>>> sky(m, vector<complex<double>>(32768));
    vector<vector<complex<double>>> telescope(m, vector<complex<double>>(32768));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> sky[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
            cin >> telescope[i][l - j - 1];
    }

    vector<complex<double>> resultSeq(32768);
    vector<long long> result(32768);
    for (int i = 0; i < m; i++)
    {
        fft(sky[i]);
        fft(telescope[i]);

        for (int j = 0; j < 32768; j++)
        {
            resultSeq[j] = sky[i][j] * telescope[i][j];
        }

        ifft(resultSeq);

        for (int j = 0; j < 32768; j++)
            result[j] += static_cast<long long>(round(resultSeq[j].real() / 32768));
    }

    int over = 0;
    for (int i = l - 1; i < n; i++)
    {
        if (result[i] > w)
            over++;
    }
    cout << over;
}
