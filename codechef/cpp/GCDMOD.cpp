#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll power(ll num, ll n, ll c=mod)
{
    ll temp = 1;
    while (n)
    {
        if (n % 2)
        {
            temp = ((temp % c) * (num % c) % c);
            n--;
        }
        num = ((num % c) * (num % c) % c);
        n /= 2;
    }

    return temp;
}

ll gcd(ll a, ll b, ll n)
{
    ll c = a - b, temp, result = 1;
    if (c == 0)
    {
        return (power(a, n) + power(b, n)) % mod;
    }

    for (ll i = 1; i * i <= c; i++)
    {
        if (c % i == 0)
        {
            temp = (power(a, n, i) + power(b, n, i)) % i;
            if (temp == 0)
            {
                result = max(result, i);
            }

            temp = (power(a, n, c / i) + power(b, n, c / i)) % (c/i);

            if (temp == 0)
            {
                result = max(result, c / i);
            }
        }
    }
    return result % mod;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    ll a, b, n;

    while (t--)
    {
        cin >> a >> b >> n;
        cout << gcd(a, b, n) << endl;
    }

    return 0;
}