#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 100001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll s;
int L = 1, R = 0;
int n, k;
int arr[maxN];
ll dp[21][maxN];
int fre[maxN];

void add(int index)
{
    s += fre[arr[index]];
    fre[arr[index]]++;
}

void remove(int index)
{
    fre[arr[index]]--;
    s -= fre[arr[index]];
}

ll change(int l, int r)
{
    while (R < r)
        add(++R);
    while (L > l)
        add(--L);
    while (R > r)
        remove(R--);
    while (L < l)
        remove(L++);

    return s;
}

void dcopt(int l, int r, int optL, int optR, int k)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;

    ll ans = 1e18, index = -1;

    REP(i, optL, min(optR, mid))
    if (dp[k - 1][i - 1] + change(i, mid) < ans)
        ans = dp[k - 1][i - 1] + change(i, mid), index = i;

    dp[k][mid] = ans;
    dcopt(l, mid - 1, optL, index, k), dcopt(mid + 1, r, index, optR, k);
}

void solve()
{
    cin >> n >> k;

    REP(i, 1, n)
    cin >> arr[i];

    REP(i, 0, n)
    REP(j, 0, k)
    dp[j][i] = 1e18;

    dp[0][0] = 0;

    REP(i, 1, k)
    dcopt(1, n, 1, n, i);

    cout << dp[k][n];
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