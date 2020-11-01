#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

unsigned ll binexp(unsigned ll a, unsigned ll power, unsigned ll m)
{
    unsigned ll res = 1;

    while (power)
    {
        if (power % 2)
        {
            power--;
            res = (res * a) % m;
        }
        power /= 2;
        a = (a * a) % m;
    }

    return res;
}

bool isComposite(unsigned ll a, unsigned ll d, unsigned ll s, unsigned ll n)
{
    unsigned ll res = binexp(a % n, d, n);

    if (res == n - 1 || res == 1)
    {
        return false;
    }

    for (unsigned ll i = 1; i < s; i++)
    {
        res = (res * res) % n;

        if (res == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool isPrime(unsigned ll n)
{
    if (n <= 5)
    {
        return (n == 2 || n == 3 || n == 5);
    }

    unsigned ll d = n - 1;
    unsigned ll s = 0;

    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (unsigned ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (p == n)
        {
            return true;
        }

        if (isComposite(p, d, s, n))
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
    cin >> t;
    unsigned ll n;

    while (t--)
    {
        cin >> n;

        if (isPrime(n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}