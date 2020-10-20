#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define maxN 10001
#define REP(i, a, b) for (int i = a; i < b; i++)

vector <ll> phi;

void init()
{
    for (ll i = 0; i < maxN; i++)
    {
        phi.push_back(i);
    }

    for (ll i = 2; i < maxN; i++)
    {
        if (phi[i] == i)
        {
            for (ll j = i; j < maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}

ll sumGcd(ll n)
{
    ll result = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result += i * phi[n / i];

            if (i * i != n)
            {
                result += (n / i) * phi[i];
            }
        }
    }
    
    return result;
}

ll modInverse(ll a, ll power, ll p=mod)
{
    ll res = 1;
    while (power)
    {
        if (power % 2)
        {
            power--;
            res = (res * a) % p;
        }
        power /= 2;
        a = ((a  % p)* (a  % p)) % p;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    ll n, sum, gcd;

    cin >> t;

    while (t--)
    {
        cin >> n;
        sum = sumGcd(n);
        gcd = __gcd(sum, n);

        // now sum and n is made co-prime
        sum /= gcd;
        n /= gcd;

        //found modulo inverse of n
        n = modInverse(n, mod - 2);
        cout<<(sum * n) % mod<<endl;
    }

    return 0;
}