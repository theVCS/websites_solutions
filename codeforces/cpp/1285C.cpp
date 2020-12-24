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

ll __lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, res = __LONG_LONG_MAX__;
    map<pair<ll, ll>, ll> arr;
    pair<ll, ll> fac;

    cin >> n;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && __lcm(i, n / i) == n)
        {
            arr[{i, n / i}] = max(i, n / i);
        }
    }

    for (auto e : arr)
    {
        if (e.second < res)
        {
            fac = e.first;
            res = e.second;
        }
    }

    cout << fac.first << " " << fac.second;

    return 0;
}