#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
ll a[15];
ll c[15];
ll dp[15][1<<15];

ll fun(int prev=0, int bitmask = 0)
{
    if (bitmask == (1 << n) - 1)
        return 0;
    
    if(dp[prev][bitmask]!=-1)
        return dp[prev][bitmask];

    int cnt = 0;

    REP(i, 0, n - 1)
    if (bitmask & (1 << i))
        cnt++;

    ll res = 1e18;

    REP(i, 0, n - 1)
    {
        if (bitmask & (1 << i))
            continue;
        ll val = (cnt == 0) ? 0 : abs(a[i] - a[prev]) * c[cnt];
        res = min(res, val + fun(i, bitmask | (1 << i)));
    }

    return dp[prev][bitmask] = res;
}

void solve()
{
    cin >> n;

    REP(i, 0, n - 1)
    cin >> a[i];

    REP(i, 0, n - 1)
    cin >> c[i];

    memset(dp,-1,sizeof(dp));
    cout << fun() << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}