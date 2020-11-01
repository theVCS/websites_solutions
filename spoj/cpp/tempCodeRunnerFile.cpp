#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll binexp(ll a, ll power, ll m)
{
    ll res = 1;

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

bool isComposite(ll a, ll d, ll s, ll n)
{
    ll res = binexp(a % n, d, n);

    if (res == n - 1 || res == 1)
    {
        return false;
    }

    for (int i = 1; i < s; i++)
    {
        res = (res * res) % n;

        if (res == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool isPrime(ll n)
{
    ll d = n - 1;
    ll s = 0;

    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
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
    cin>>t;
    ll n;

    while (t--)
    {
        cin>>n;

        if (isPrime(n))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    

    return 0;
}