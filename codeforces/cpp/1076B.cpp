#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
ll cnt = 0;

void algo(ll n, ll k)
{
    ll i;
    bool b = true;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n -= i;
                cnt++;
            }

            b = false;
            break;
        }
    }

    if (b)
    {
        cnt++;
        n = 0;
        return;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;

    cin >> n;
    algo(n, 2);

    cout << cnt;

    return 0;
}