#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll binProd(ll n, ll power, ll m)
{
    ll res = 1;
    while (power)
    {
        if (power % 2)
        {
            power--;
            res = (res * (n % m)) % m;
        }
        power /= 2;
        n = ((n % m) * (n % m)) % m;
    }
    return res;
}

bool isPrime(ll n)
{
    if (n <= 5)
    {
        return (n == 2 || n == 3 || n == 5);
    }

    ll a;
    for (int i = 0; i <= 10; i++)
    {
        a = 2 + rand() % (n - 3);
        if (binProd(a, n - 1, n) != 1)
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
    cout.tie(0);

    int t;
    ll n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (isPrime(n))
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