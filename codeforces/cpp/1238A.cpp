#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

bool isPossible(ll n)
{
    ll noP = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            noP++;
            if (noP)
            {
                return true;
            }
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        noP++;
    }

    if (noP)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t;
    ll x, y;

    cin >> t;

    while (t--)
    {
        cin >> x >> y;
        if (isPossible(x - y))
        {
            cout << "YES"<<endl;
        }
        else
        {
            cout << "NO"<<endl;
        }
    }

    return 0;
}