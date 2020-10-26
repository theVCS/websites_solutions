#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll winner(ll n)
{
    ll pos, win = 1;

    while (n > 1)
    {
        if (!(n & (n - 1)))
        {
            n /= 2;
            win++;
        }
        else
        {
            for (int i = 63; i >= 0; i--)
            {
                if (n & (1LL << i))
                {
                    n -= (1LL << i);
                    break;
                }
            }
            win++;
        }
    }

    return (win % 2);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        if (winner(n))
        {
            cout << "Richard\n";
        }
        else
        {
            cout << "Louise\n";
        }
    }

    return 0;
}