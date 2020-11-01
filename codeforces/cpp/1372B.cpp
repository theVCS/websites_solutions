#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll fact(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n, k;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n % 2)
        {
            k = fact(n);

            if (k == 1)
            {
                cout << n - k << " " << k << endl;
            }
            else
            {

                cout << n / k << " " << (n * (k - 1)) / k << endl;
            }
        }
        else
        {
            cout << n / 2 << " " << n / 2 << endl;
        }
    }

    return 0;
}