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
ll arr[101];
ll prefix[101];
ll dp[101][101];

ll fun(int i, int j)
{
    // cout<<i<<" "<<j<<endl;
    if (i >= j)
        return 0;
    else if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        ll ans = 1e18;

        REP(index, i, j-1)
        {
            ll l = (prefix[index]-prefix[i-1]) % 100;
            ll r = (prefix[j] - prefix[index]) % 100;
            ans = min(ans,l*r+fun(i,index)+fun(index+1,j));
        }

        return dp[i][j] = ans;
    }
}

void solve()
{
    while (cin >> n)
    {
        REP(i, 1, n)
        {
            cin >> arr[i];
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        memset(dp,-1,sizeof(dp));
        cout << fun(1, n) << endl;
    }
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