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

    vector<int> primes = {
        3, 5, 7,
        11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
        211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
        307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
        401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
        503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
        601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
        701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
        809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
        907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
};

    auto complex0 = complex<double>();
    auto complex1 = complex<double>(1);
    vector<complex<double>> pSeq(2097152), spSeq(2097152);
    vector<int> primeSeq(2097152);

    for (int i = 0; i <= 500000; i++)
    {
        primeSeq[i] = 1;
        pSeq[i] = complex1;
        if (i % 2 == 0)
            spSeq[i] = complex1;
    }

    for (int p : primes)
    {
        for (int j = 3; p * j <= 1000000; j += 2)
        {
            primeSeq[(p * j) / 2 - 1] = 0;
            pSeq[(p * j) / 2 - 1] = complex0;
            spSeq[(p * (j + 1)) / 2 - 3] = complex0;
        }
    }

    fft(pSeq);
    fft(spSeq);

    vector<complex<double>> resultSeq(2097152);
    vector<complex<double>> resultSeq2(2097152);
    for (int i = 0; i < 2097152; i++)
    {
        resultSeq[i] = pSeq[i] * pSeq[i] * pSeq[i];
        resultSeq2[i] = pSeq[i] * spSeq[i];
    }

    ifft(resultSeq);
    ifft(resultSeq2);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        long long c = (n % 3 == 0 && primeSeq[n / 6 - 1] == 1) ? 1 : 0;
        long long b = round(resultSeq2[n / 2 - 4].real() / 2097152);
        long long a = round(resultSeq[n / 2 - 4].real() / 2097152);

        b -= c;

        long long result = (primeSeq[(n - 4) / 2 - 1] == 1) ? 1 : 0;

        result += (a - 3 * b - c) / 6 + b + c;
        cout << result << '\n';
    }
}