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

string str;
ll dp[10][82];
int N;

ll digitDP(int pos, int flag = 1, int val = 0)
{
    if (pos == -1)
        return val;

    ll &res = dp[pos][val];

    if (flag == 0 && res != -1)
        return res;

    ll ans = 0;
    int ub = flag ? (str[pos] - '0') : 9;

    REP(i, 0, ub)
    {
        ans += digitDP(pos - 1, (i == ub & flag), val + i);
    }

    return flag ? ans : res = ans;
}

int check(string &s)
{
    ll ans = 0;

    for (char &c : s)
    {
        ans += (c - '0');
    }

    return ans;
}

void solve()
{
    ll ans = 0;

    string l, r;
    cin >> l >> r;

    str = l;
    reverse(all(str));
    N = str.size();
    ans -= digitDP(N - 1);
    ans += check(str);

    str = r;
    reverse(all(str));
    N = str.size();
    ans += digitDP(N - 1);

    cout << ans << endl;
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
    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}