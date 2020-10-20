#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void modPower(ll n, ll p, ll m)
{
    ll res = 1, dum = n;
    while (p > 0)
    {
        if (p % 2)
        {
            p--;
            res = (res * (n % m)) % m;
        }
        p /= 2;
        n = ((n % m) * (n % m)) % m;
    }

    cout << dum - res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t;
    ll x, a, b;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> x;

        if (b < 0)
        {
            if (a > 1)
            {
                cout << 0 << endl;
            }
            else
            {
                if (x == 1)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
        }
        else
        {
            modPower(a, b, x);
        }
        
    }

    return 0;
}