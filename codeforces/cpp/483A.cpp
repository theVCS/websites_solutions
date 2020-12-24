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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll l, r, a = 0, b = 0, c = 0;

    cin >> l >> r;

    for (ll i = l; i < r + 1; i++)
    {
        for (ll j = i + 1; j < r + 1; j++)
        {
            for (ll k = j + 1; k < r + 1; k++)
            {
                if (__gcd(i, j) == 1 && __gcd(j, k) == 1 && __gcd(i, k) != 1)
                {
                    a = i;
                    b = j;
                    c = k;
                    i = r;
                    j = r;
                    k = r;
                }
            }
        }
    }

    if (c)
    {
        cout << a << " " << b << " " << c;
    }
    else
    {
        cout << -1;
    }

    return 0;
}