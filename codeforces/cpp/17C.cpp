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

int N;
string s;

int find(int pos, char c)
{
    REP(i, pos, N - 1)
    {
        if (s[i] == c)
            return i;
    }

    return -1;
}

int check(int fa, int fb, int fc)
{
    int diff = -1;

    diff = abs(fa - fb);
    if (diff > 1)
        return 0;

    diff = abs(fa - fc);
    if (diff > 1)
        return 0;

    diff = abs(fc - fb);
    if (diff > 1)
        return 0;

    return 1;
}

int dp[151][52][52][52];

ll fun(int pos, int fa, int fb, int fc)
{
    if (fa > (N + 2) / 3 || fb > (N + 2) / 3 || fc > (N + 2) / 3)
        return 0;
    if(fa+fb+fc==N)
        return check(fa,fb,fc);
    else if(dp[pos][fa][fb][fc] !=-1)
        return dp[pos][fa][fb][fc];
    else
    {
        int ia = find(pos, 'a');
        int ib = find(pos, 'b');
        int ic = find(pos, 'c');

        ll ans = 0;

        if (ia >= 0)
            ans += fun(ia, fa + 1, fb, fc), ans %= 51123987;
        if (ib >= 0)
            ans += fun(ib, fa, fb + 1, fc), ans %= 51123987;
        if (ic >= 0)
            ans += fun(ic, fa, fb, fc + 1), ans %= 51123987;

        return dp[pos][fa][fb][fc] = ans;
    }
}

void solve()
{
    cin >> N >> s;
    memset(dp,-1,sizeof(dp));
    cout << fun(0, 0, 0, 0);
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