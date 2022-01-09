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

int n, m, k;
int dp[31][31][51];

int fun(int h, int w, int k)
{
    if (h * w < k || k < 0)
        return INF;

    if (h * w == k || k == 0)
        return 0;

    if (dp[h][w][k] != -1)
        return dp[h][w][k];

    int ans = INF;

    REP(nw, 1, w / 2)
    {
        int w1 = nw;
        int w2 = w - nw;

        REP(nk, 0, k)
        {
            int cost = h * h + fun(h, w1, nk) + fun(h, w2, k - nk);
            ans = min(ans, cost);
        }
    }

    REP(nh, 1, h / 2)
    {
        int h1 = nh;
        int h2 = h - nh;

        REP(nk, 0, k)
        {
            int cost = w * w + fun(h1, w, nk) + fun(h2, w, k - nk);
            ans = min(ans, cost);
        }
    }

    return dp[h][w][k] = ans;
}

void solve()
{
    cin >> n >> m >> k;
    cout << fun(n, m, k) << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    memset(dp, -1, sizeof(dp));

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}