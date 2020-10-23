#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n = 600851475143, lp;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            lp = i;

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n  > 1)
    {
        lp = max(n, lp);
    }
    
    cout<<lp;

    return 0;
}