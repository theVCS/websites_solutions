#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 20000025
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll sieve[maxN];
ll sumInv[100000001];

void init()
{
    for (ll i = 2; i < maxN; i++)
    {
        if (sieve[i] == 0)
        {
            for (ll j = i; j < maxN; j += i)
            {
                if (sieve[j] == 0)
                {
                    sieve[j] = i;
                }
            }
        }
    }
}

map<ll, ll> primefact(ll n)
{
    map<ll, ll> fact;

    while (sieve[n])
    {
        fact[sieve[n]] += 1;
        n = n / sieve[n];
    }
    return fact;
}

ll binExp(ll n, ll pow)
{
    ll res = 1;
    while (pow)
    {
        if (pow % 2)
        {
            res *= n;
            pow--;
        }
        n *= n;
        pow /= 2;
    }
    return res;
}

ll divSum(ll n)
{
    ll sum = 1;
    map<ll, ll> fact = primefact(n);

    for (auto p : fact)
    {
        sum *= ((binExp(p.first, p.second + 1) - 1LL) / (p.first - 1));
    }
    return sum;
}

void init2()
{
    ll sumn;
    for (ll i = 1; i < maxN; i++)
    {
        sumn = divSum(i);
        
        if (sumn <= 100000000 && sumInv[sumn] == 0)
        {
            sumInv[sumn] = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    init2();

    ll t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (sumInv[n] == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << sumInv[n] << endl;
        }
    }

    return 0;
}