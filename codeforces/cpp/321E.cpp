#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 4001
#define INF 1000000000000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, k;
ll matrix[maxN][maxN];
ll dp[801][maxN];

ll calc(int i, int j)
{
    return (matrix[j][j] - matrix[i - 1][j] - matrix[j][i - 1] + matrix[i - 1][i - 1]) / 2;
}

void dc(int l, int r, int optL, int optR, int k)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    int index = 0;
    dp[k][mid] = INF;

    REP(i, optL, min(optR, mid - 1))
    {
        ll v = dp[k - 1][i] + calc(i + 1, mid);
        if (dp[k][mid] > v)
            dp[k][mid] = v, index = i;
    }

    dc(l, mid - 1, optL, index, k), dc(mid + 1, r, index, optR, k);
}

void solve()
{
    cin>>n>>k;
    cin.ignore();
    
    REP(i, 1, n)
    {
        string s;
        getline(cin, s);

        REP(j, 1, n)
        {
            matrix[i][j] = s[(j - 1) * 2] - '0';
            matrix[i][j] += matrix[i][j - 1];
            matrix[i][j] += matrix[i - 1][j];
            matrix[i][j] -= matrix[i - 1][j - 1];
        }
    }

    REP(i, 1, n)
    dp[1][i] = calc(1, i);

    REP(i, 2, k)
    dc(1, n, 1, n, i);

    // printf("%lld", dp[k][n]);
    cout<<dp[k][n]<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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