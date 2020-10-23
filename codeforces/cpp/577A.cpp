#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<ll> fac;

void init(ll n)
{
    if (n == 1)
    {
        fac.push_back(1);
        return;
    }
    
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fac.push_back(i);

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        fac.push_back(n);
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll cnt = 0;
    ll n, x, d1, d2;
    cin >> n >> x;

    init(x);

    for(ll P: fac)
    {
        cout<<P<<" ";
    }

    // for (ll P : fac)
    // {
    //     d1 = P;
    //     d2 = x / P;
    //     if (d1 <= n && d2 <= n)
    //     {
    //         if (d1 == d2)
    //         {
    //             cnt++;
    //         }
    //         else
    //         {
    //             cnt += 2;
    //         }
    //     }
    // }

    // cout << cnt;
    return 0;
}