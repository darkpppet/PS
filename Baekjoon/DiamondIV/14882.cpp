#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr long long p = 786'433;
constexpr long long originW = 10;
constexpr long long two_b = 786'432;
void ntt(vector<long long> &seq, long long w)
{
    const auto n = seq.size();
    if (n == 3)
    {
        long long w2 = (w * w) % p;
        long long w4 = (w2 * w2) % p;

        long long a0 = seq[0];
        long long a1 = seq[1];
        long long a2 = seq[2];

        seq[0] = (((a0 + a1) % p) + a2) % p;
        seq[1] = (((a0 + (a1 * w) % p) % p) + (a2 * w2) % p) % p;
        seq[2] = (((a0 + (a1 * w2) % p) % p) + (a2 * w4) % p) % p;

        return;
    }

    vector<long long> evenSeq(n / 2);
    vector<long long> oddSeq(n / 2);

    for(int i = 0; i < n / 2; i++)
    {
        evenSeq[i] = seq[i * 2];
        oddSeq[i] = seq[i * 2 + 1];
    }

    long long w2 = (w * w) % p;
    ntt(evenSeq, w2);
    ntt(oddSeq, w2);

    long long nowW = 1;
    for (int i = 0; i < n / 2; i++)
    {
        auto e = evenSeq[i];
        auto o = (oddSeq[i] * nowW) % p;

        seq[i] = (e + o) % p;
        seq[n / 2 + i] = (e - o + p) % p;

        nowW *= w;
        nowW %= p;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(two_b);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<long long> result(two_b);
    result[0] = a[0];

    ntt(a, originW);

    long long g = 1;
    for (int i = 0; i < two_b; i++)
    {
        result[g] = a[i];

        g *= 10;
        g %= p;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int ki;
        cin >> ki;
        cout << result[ki] << '\n';
    }
}
