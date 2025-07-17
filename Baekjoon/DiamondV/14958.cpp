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

    int n, m;
    cin >> n >> m;

    string rps;
    cin >> rps;

    string my;
    cin >> my;
    reverse(my.begin(), my.end());

    vector<complex<double>> rpsSeq(262144);
    vector<complex<double>> mySeq(262144);

    for (int i = 0; i < n; i++)
    {
        rpsSeq[i] = rps[i] == 'R' ? 1 : 0;
        if (i < m)
        {
            mySeq[i] = my[i] == 'P' ? 1 : 0;
        }
    }

    fft(rpsSeq);
    fft(mySeq);

    vector<complex<double>> resultSeq(262144);
    for (int i = 0; i < 262144; i++)
        resultSeq[i] = rpsSeq[i] * mySeq[i];

    ifft(resultSeq);

    vector<int> result(262144);
    for (int i = 0; i < 262144; i++)
        result[i] += static_cast<int>(round(resultSeq[i].real() / 262144));

    for (int i = 0; i < 262144; i++)
    {
        if (i < n)
            rpsSeq[i] = rps[i] == 'P' ? 1 : 0;
        else
            rpsSeq[i] = 0;
        if (i < m)
            mySeq[i] = my[i] == 'S' ? 1 : 0;
        else
            mySeq[i] = 0;
    }

    fft(rpsSeq);
    fft(mySeq);

    for (int i = 0; i < 262144; i++)
        resultSeq[i] = rpsSeq[i] * mySeq[i];

    ifft(resultSeq);

    for (int i = 0; i < 262144; i++)
        result[i] += static_cast<int>(round(resultSeq[i].real() / 262144));

    for (int i = 0; i < 262144; i++)
    {
        if (i < n)
            rpsSeq[i] = rps[i] == 'S' ? 1 : 0;
        else
            rpsSeq[i] = 0;
        if (i < m)
            mySeq[i] = my[i] == 'R' ? 1 : 0;
        else
            mySeq[i] = 0;
    }

    fft(rpsSeq);
    fft(mySeq);

    for (int i = 0; i < 262144; i++)
        resultSeq[i] = rpsSeq[i] * mySeq[i];

    ifft(resultSeq);

    for (int i = 0; i < 262144; i++)
        result[i] += static_cast<int>(round(resultSeq[i].real() / 262144));

    int maxWin = 0;
    for (int i = m - 1; i < n + m; i++)
        maxWin = max(maxWin, result[i]);
    cout << maxWin;
}
