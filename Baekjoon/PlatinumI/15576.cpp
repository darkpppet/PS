#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

void fft(vector<complex<long double>> &seq)
{
    int n = seq.size();
    if (n == 1)
        return;

    vector<complex<long double>> evenSeq(n / 2);
    vector<complex<long double>> oddSeq(n / 2);

    for(int i = 0; i < n / 2; i++)
    {
        evenSeq[i] = seq[i * 2];
        oddSeq[i] = seq[i * 2 + 1];
    }

    fft(evenSeq);
    fft(oddSeq);

    complex<long double> w(cos(2*M_PI/n), -sin(2*M_PI/n));
    complex<long double> nowW(1);
    for (int i = 0; i < n / 2; i++)
    {
        seq[i] = evenSeq[i] + oddSeq[i] * nowW;
        seq[n / 2 + i] = evenSeq[i] - oddSeq[i] * nowW;
        nowW *= w;
    }
}

void ifft(vector<complex<long double>> &seq)
{
    int n = seq.size();
    if (n == 1)
        return;

    vector<complex<long double>> evenSeq(n / 2);
    vector<complex<long double>> oddSeq(n / 2);

    for(int i = 0; i < n / 2; i++)
    {
        evenSeq[i] = seq[i * 2];
        oddSeq[i] = seq[i * 2 + 1];
    }

    ifft(evenSeq);
    ifft(oddSeq);

    complex<long double> w(cos(2*M_PI/n), sin(2*M_PI/n));
    complex<long double> nowW(1);
    for (int i = 0; i < n / 2; i++)
    {
        seq[i] = evenSeq[i] + oddSeq[i] * nowW;
        seq[n / 2 + i] = evenSeq[i] - oddSeq[i] * nowW;
        nowW *= w;
    }
}

int chunckSize = 2;
int digit = pow(10, chunckSize);

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

    vector<complex<long double>> aSeq, bSeq;
    for (int i = 1; i <= length; i++)
    {
        if (aLength - i * chunckSize >= 0)
            aSeq.push_back(complex<long double>(stoi(a.substr(aLength - i * chunckSize, chunckSize))));
        else if (aLength - (i - 1) * chunckSize > 0)
            aSeq.push_back(complex<long double>(stoi(a.substr(0, aLength - (i - 1) * chunckSize))));
        else
            aSeq.push_back(complex<long double>());

        if (bLength - i * chunckSize >= 0)
            bSeq.push_back(complex<long double>(stoi(b.substr(bLength - i * chunckSize, chunckSize))));
        else if (bLength - (i - 1) * chunckSize > 0)
            bSeq.push_back(complex<long double>(stoi(b.substr(0, bLength - (i - 1) * chunckSize))));
        else
            bSeq.push_back(complex<long double>());
    }

    fft(aSeq);
    fft(bSeq);

    vector<complex<long double>> resultSeq;
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
