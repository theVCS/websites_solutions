#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 50001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, k;

vector<int> arr[maxN];
int dp[maxN][501];
int dp2[maxN][201];
ll res;

void dfs(int node = 1, int par = -1)
{
    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node);

            REP(i, 1, k + 1)
            {
                dp[node][i] += dp[child][i - 1];
                dp2[node][i] = dp[node][i];
            }
        }
    }

    dp[node][0] = 1;
}

void solve(int node = 1, int par = -1)
{
    if (par != -1)
    {
        dp2[node][0] = 1;
        dp2[node][1] = dp[node][1] + 1;

        REP(i, 2, k + 1)
        {
            dp2[node][i] = dp[node][i] + dp2[par][i - 1] - dp[node][i - 2];
        }
    }

    res += dp2[node][k] * 1LL;

    for (int child : arr[node])
    {
        if (child != par)
            solve(child, node);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n >> k;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs();
    solve();

    cout << res/2;

    return 0;
}