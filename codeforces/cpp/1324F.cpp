#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int col[maxN];
int dp[maxN];
int ans[maxN];

void dfs(int node = 1, int par = -1)
{
    int sum = col[node];

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node);

        if (dp[child] > 0)
            sum += dp[child];
    }

    dp[node] = sum;
}

void sol(int node = 1, int par = 0)
{
    int parAns = ans[par], childParAns = 0;

    //excluding effect of node in parent's answer
    if (dp[node] > 0)
        parAns -= dp[node];

    if (parAns > 0)
        ans[node] = parAns + dp[node];
    else
        ans[node] = dp[node];

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        sol(child, node);

        if (dp[child] > 0)
            childParAns += dp[child];
    }
}

void solve()
{
    int n, a, b;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> col[i];

        if (col[i] == 0)
            col[i] = -1;
    }

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs();
    sol();
    // 2 1 2 1 0 -1 -1 -1 1
    REP(i, 1, n + 1)
    cout << ans[i] << " ";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}