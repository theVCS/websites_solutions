#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll binexp(ll n, ll power, ll m)
{
    ll res = 1;

    while (power)
    {
        if (power % 2)
        {
            power--;
            res = (res * n) % m;
        }
        power /= 2;
        n = (n * n) % m;
    }
    return res;
}

bool isComposite(ll a, ll d, ll s, ll n)
{
    ll res = binexp(a % n, d, n);

    if (res == 1 || res == n - 1)
    {
        return false;
    }

    for (ll i = 1; i < s; i++)
    {
        res = (res * res) % n;

        if (res == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool millerRabin(ll n)
{
    if (n <= 4)
    {
        return n == 2 || n == 3;
    }

    ll d = n - 1, s = 0;

    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
        {
            return true;
        }

        if (isComposite(a, d, s, n))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        if (millerRabin(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}