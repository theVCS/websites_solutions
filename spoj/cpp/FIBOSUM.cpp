#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll trans[2][2], unit[2][2];

void multiply(ll a[][2], ll b[][2])
{
    ll res[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                res[i][j] += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[i][j] = res[i][j];
        }
    }
}

void binexp(ll power)
{
    trans[0][0] = 0;
    trans[0][1] = trans[1][0] = trans[1][1] = 1;

    unit[0][0] = unit[1][1] = 1;
    unit[1][0] = unit[0][1] = 0;

    while (power)
    {
        if (power % 2)
        {
            power--;
            multiply(trans, unit);
        }
        power /= 2;
        multiply(trans, trans);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n, m, sum1, sum2;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        binexp(n + 1);
        sum1 = unit[1][0];

        binexp(m + 2);
        sum2 = unit[1][0];

        cout << (mod + (sum2 - sum1) % mod) % mod << endl;
    }

    return 0;
}