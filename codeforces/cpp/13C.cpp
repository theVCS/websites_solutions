#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 5001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
int arr[maxN];
int brr[maxN];
ll dp[maxN][maxN];

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i], brr[i] = arr[i];

    sort(brr + 1, brr + 1 + n);

    REP(i,0,n)
    dp[i][0]=dp[0][i]=1e18;

    REP(i, 1, n)
    REP(j, 1, n)
    {
        if (i == 1 && j == 1)
            dp[i][j] = abs(arr[i] - brr[j]);
        if (i == 1)
            dp[i][j] = min(1LL*abs(arr[i] - brr[j]), dp[i][j-1]);
        else if (j == 1)
            dp[i][j] = (abs(arr[i] - brr[j]) +  dp[i-1][j]);
        else
            dp[i][j] = min(abs(arr[i] - brr[j]) + dp[i-1][j], dp[i][j-1]);
    }

    cout<<dp[n][n];
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