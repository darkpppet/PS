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

    long long n;
    cin >> n;

    vector<complex<double>> a(1048576);
    vector<int> b(1048576);
    complex<double> complex1(1);
    for (long long i = 1; i < n; i++)
    {
        a[(i * i) % n] += complex1;
        b[(2 * i * i) % n] += 1;
    }

    fft(a);

    for (int i = 0; i < 1048576; i++)
        a[i] *= a[i];

    ifft(a);

    long long result = 0;
    long long aEqualBCount = 0;
    for (long long i = 1; i < n; i++)
    {
        result += round(a[(i * i) % n].real() / 1048576);
        result += round(a[(i * i) % n + n].real() / 1048576);

        aEqualBCount += b[(i * i) % n];
    }

    result -= aEqualBCount;
    result /= 2;
    result += aEqualBCount;

    cout << result;
}