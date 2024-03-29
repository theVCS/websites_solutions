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

string str1;
string str2;
ll dp[51][18][18][18];
int N;

ll digitDP(int pos, int flag1 = 1, int flag2 = 1, int c3 = 0, int c6 = 0, int c9 = 0)
{
    if(c3>N/3||c6>N/3||c9>N/3)
        return 0;
    if (pos == -1)
        return c3 && c3 == c6 && c6 == c9;

    ll &res = dp[pos][c3][c6][c9];

    if (flag1 == 0 && flag2 == 0 && res != -1)
        return res;

    ll ans = 0;
    
    int lb = flag1 ? (str1[pos] - '0') : 0;
    int ub = flag2 ? (str2[pos] - '0') : 9;

    REP(i, lb, ub)
    {
        ans += digitDP(pos - 1, (i==lb && flag1), (i == ub & flag2), c3+(i==3),c6+(i==6),c9+(i==9));
        ans %= mod;
    }

    return flag1==0 && flag2==0 ? res = ans: ans;
}

void solve()
{
    cin >> str1 >> str2;

    reverse(all(str1));
    reverse(all(str2));

    while (str1.size() < str2.size())
    {
        str1.push_back('0');
    }

    N = str1.size();
    ll ans = digitDP(N - 1);
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
    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}