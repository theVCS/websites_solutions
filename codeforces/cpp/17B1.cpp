#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<ll> fact(ll n)
{
    vector<ll> factors;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);

            if (n != i * i)
            {
                factors.push_back(n / i);
            }
        }
    }
    factors.push_back(n);

    return factors;
}

ll maxres(ll n)
{
    vector<ll> factors = fact(n);
    ll res = 0;
    ll a, b;

    for (ll fac : factors)
    {
        a = fac;
        b = n / fac;

        if (b == 1)
        {
            res = (n + b);
        }
        else
        {
            res = max(res, b + maxres(b));
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;

    cin >> n;

    cout << maxres(n);

    return 0;
}