#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
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

long long chunckSize = 2;
long long digit = pow(10, chunckSize);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    if ((a.length() == 1 && a[0] == '0') || (b.length() == 1 && b[0] == '0'))
    {
        cout << 0;
        return 0;
    }

    int aLength = a.length();
    int bLength = b.length();

    int aChunkLength = ceil(aLength / (double)chunckSize);
    int bChunkLength = ceil(bLength / (double)chunckSize);

    int length = pow(2, ceil(max(log2(aChunkLength), log2(bChunkLength))) + 1);

    vector<complex<double>> aSeq, bSeq;
    for (int i = 1; i <= length; i++)
    {
        if (aLength - i * chunckSize >= 0)
            aSeq.push_back(complex<double>(stoi(a.substr(aLength - i * chunckSize, chunckSize))));
        else if (aLength - (i - 1) * chunckSize > 0)
            aSeq.push_back(complex<double>(stoi(a.substr(0, aLength - (i - 1) * chunckSize))));
        else
            aSeq.push_back(complex<double>());

        if (bLength - i * chunckSize >= 0)
            bSeq.push_back(complex<double>(stoi(b.substr(bLength - i * chunckSize, chunckSize))));
        else if (bLength - (i - 1) * chunckSize > 0)
            bSeq.push_back(complex<double>(stoi(b.substr(0, bLength - (i - 1) * chunckSize))));
        else
            bSeq.push_back(complex<double>());
    }

    fft(aSeq);
    fft(bSeq);

    vector<complex<double>> resultSeq;
    for (int i = 0; i < length; i++)
        resultSeq.push_back(aSeq[i] * bSeq[i]);

    ifft(resultSeq);

    long long remain = 0;
    vector<long long> result;
    for (auto k : resultSeq)
    {
        remain += round(k.real() / length);
        result.push_back(remain % digit);
        remain /= digit;
    }
    result.push_back(remain);

    reverse(result.begin(), result.end());

    int index = 0;
    while (result[index] <= 0)
        index++;

    cout << result[index];
    index++;

    for (int i = index; i < result.size(); i++)
        cout << setfill('0') << setw(chunckSize) << result[i];
}
