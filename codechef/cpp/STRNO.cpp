#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

bool isPossible(ll x, ll y)
{
    ll cnt = 0;

    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {

            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
        }
    }

    if (x > 1)
    {
        cnt++;
    }

    if (cnt < y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll x, k;

    cin >> t;

    while (t--)
    {
        cin >> x >> k;
        if (isPossible(x, k))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}