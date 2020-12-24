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

int t, m, n;

ll binexp(ll a, ll pow, ll m = mod)
{
    ll res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            pow--;
            res = (res * a) % m;
        }
        pow /= 2;
        a = (a * a) % m;
    }
    return res;
}

ll f(int n)
{
    if (n == 1)
    {
        return m;
    }
    else
    {
        return (m * binexp(2, n - 2)) % mod;
    }
}

ll largestfact(ll n)
{
    ll res = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res = max(res, i);

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        res = max(res, n);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll sum = 0, cn;

    cin >> t >> m;

    while (t--)
    {
        cin >> n;
        cn = (n + m + f(n)) % mod;

        sum += largestfact(cn);
    }

    cout << "The President needs to pay " << sum << " dollar(s)";

    return 0;
}