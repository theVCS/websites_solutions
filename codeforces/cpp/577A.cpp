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

ll counter(ll n, ll x)
{
    int cnt = 0;

    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (i <= n && x / i <= n)
            {
                if (i * i == x)
                {
                    cnt++;
                }
                else
                {
                    cnt += 2;
                }
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x;

    cin >> n >> x;

    cout << counter(n, x);

    return 0;
}