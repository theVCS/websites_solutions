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

int N, K;
int arr[201];
ll dp[201][201][1001];

ll fun(int i, int j, int k)
{
    if (k < 0)
        return 0;
    else if (i >= N)
        return (j == 0);
    else if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    else
    {
        return dp[i][j][k] = (fun(i + 1, j, k - j * (arr[i] - arr[i - 1])) + fun(i + 1, j+1, k - j * (arr[i] - arr[i - 1])) + j*fun(i + 1, j,  k - j * (arr[i] - arr[i - 1])) + j*fun(i + 1, j - 1,  k - j * (arr[i] - arr[i - 1]))) % mod;
    }
}

void solve()
{
    cin >> N >> K;

    REP(i, 1, N)
    cin >> arr[i];

    memset(dp,-1,sizeof(dp));
    fun(1,0,K);

    ll ans = 0;
    REP(i,0,K)
    ans=(ans+dp[N][0][i])%mod;

    cout<<ans;
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