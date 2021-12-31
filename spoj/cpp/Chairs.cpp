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
#define mod 1000000003
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, k;
ll dp[1001][1001];

ll fun(int perLeft, int pos)
{
    if (perLeft == 0)
        return 1;

    int seatsLeft = (n - pos + 1) / 2;
    if (seatsLeft < perLeft || pos > n)
        return 0;
    else if (dp[perLeft][pos] != -1)
        return dp[perLeft][pos];
    else
    {
        ll ways = 0;

        REP(i, pos, n)
        ways += fun(perLeft - 1, i + 2), ways%=mod;

        return dp[perLeft][pos] = ways;
    }
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << fun(k, 1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}