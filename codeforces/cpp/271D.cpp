#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1510
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, int power)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        power >>= 1;
    }
    return res;
}

string s, badStr;
ll dp[maxN], inv[maxN];
int badCount[maxN];

void init(int n)
{
    ll p = 123;
    ll power = p;
    dp[0] = s[0] - 'a' + 1;
    badCount[0] = int(badStr[s[0] - 'a'] == '0');
    inv[0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * p) % mod;
        inv[i] = binExp(p, mod - 2);
        badCount[i] = badCount[i - 1] + int(badStr[s[i] - 'a'] == '0');
        p = (p * power) % mod;
    }
}

int query(int l, int r)
{
    int res = badCount[r];
    if (l)
        res -= badCount[l - 1];
    return res;
}

ll subHash(int l, int r)
{
    ll res = dp[r];

    if (l)
        res = (res - dp[l - 1] + mod) % mod;

    return (res * inv[l]) % mod;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    set<ll> ans;

    cin >> s >> badStr;
    cin >> k;

    n = s.size();
    init(n);

    for (int i = 0; i < n; i++)
    {
        REP(j, i, n)
        {
            int _k = query(i, j);

            if (_k > k)
                break;

            ans.insert(subHash(i, j));
        }
    }

    cout << ans.size();

    return 0;
}