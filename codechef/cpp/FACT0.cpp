#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void primesFact(ll n)
{
    ll cnt;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            cout << i << "^" << cnt << " ";
        }
    }

    if (n > 1)
    {
        cout << n << "^" << 1;
    }

    cout << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n = 1;

    while (n)
    {
        cin >> n;
        primesFact(n);
    }

    return 0;
}