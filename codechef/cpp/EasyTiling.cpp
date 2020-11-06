#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll trans[2][2], um[2][2];

void multiply(ll a[][2], ll b[][2])
{
    ll res[2][2];

    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            res[i][j] = 0;
            REP(k, 0, 2)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            b[i][j] = res[i][j] % mod;
        }
    }
}

bool binpow(ll power)
{
    trans[0][0] = 0;
    trans[0][1] = trans[1][0] = trans[1][1] = 1;

    um[0][0] = um[1][1] = 1;
    um[0][1] = um[1][0] = 0;

    while (power)
    {
        if (power % 2)
        {
            multiply(trans, um);
            power--;
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
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        binpow(n);

        cout << um[1][1] << "\n";
    }

    return 0;
}