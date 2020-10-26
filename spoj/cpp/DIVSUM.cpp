#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
int sieve[maxN];

ll binexp(ll n, ll power)
{
    ll res = 1;

    while (power)
    {
        if (power % 2)
        {
            power--;
            res = res * n;
        }
        power /= 2;
        n = n * n;
    }
    return res;
}

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i; j < maxN; j+=i)
            {
                if (sieve[j] == j)
                {
                    sieve[j] = j / i;
                }
            }
        }
    }
}

void sumFinder(int n)
{
    map<int, int> factors;
    n = n * 1LL;
    ll sum = 1, num = n;

    while (sieve[n])
    {
        if (factors.find((n / sieve[n])) == factors.end())
        {
            factors[(n / sieve[n])] = 1;
        }
        else
        {
            factors[(n / sieve[n])] += 1;
        }

        n = sieve[n];
    }

    for (auto P : factors)
    {
        sum *= (binexp(P.first, P.second + 1) - 1) / (P.first - 1);
    }

    cout << sum - num << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        sumFinder(n);
    }

    return 0;
}