#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000011
#define maxR 46350
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool sieve[maxR];
vector<ll> primes;

void init()
{
    for (int i = 2; i * i <= maxR; i++)
    {
        if (sieve[i] == false)
        {
            for (int j = i * i; j < maxR; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    REP(i, 2, maxR)
    if (!sieve[i])
        primes.push_back(i * 1LL);
}

void segSieve(ll L, ll R)
{
    if (L == 1)
        L++;

    int maxn = R - L + 1;
    vector<int> ar(maxn, 0);

    for (ll p : primes)
    {
        if (p * p <= R)
        {
            ll i = (L / p) * p;

            if (i < L)
                i += p;

            for (; i <= R; i += p)
            {
                if (i != p)
                    ar[i - L] = 1;
            }
        }
    }

    for (int i = 0; i < maxn; i++)
        if (ar[i] == 0)
            printf("%lld\n", i + L);
}

int main(int argc, char const *argv[])
{
    init();

    int t;
    ll l, r;

    cin >> t;

    while (t--)
    {
        scanf("%lld %lld", &l, &r);
        segSieve(l, r);
    }

    return 0;
}