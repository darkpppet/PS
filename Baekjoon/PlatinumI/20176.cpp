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
    for (int i = 1; i < n - 1; i++)
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
    for (int i = 1; i < n - 1; i++)
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

    int nu;
    cin >> nu;
    vector<complex<double>> uSeq(131072);
    for (int i = 0; i < nu; i++)
    {
        int x;
        cin >> x;
        uSeq[x + 30000] = 1;
    }

    int nm;
    cin >> nm;
    vector<int> mSeq;
    for (int i = 0; i < nm; i++)
    {
        int x;
        cin >> x;
        mSeq.push_back(x + 30000);
    }

    int nl;
    cin >> nl;
    vector<complex<double>> lSeq(131072);
    for (int i = 0; i < nl; i++)
    {
        int x;
        cin >> x;
        lSeq[x + 30000] = 1;
    }

    fft(uSeq);
    fft(lSeq);

    vector<complex<double>> sSeq(131072);
    for (int i = 0; i < 131072; i++)
        sSeq[i] = uSeq[i] * lSeq[i];

    ifft(sSeq);

    int sum = 0;
    for (int m : mSeq)
        sum += round(sSeq[2 * m].real() / 131072);

    cout << sum;
}
