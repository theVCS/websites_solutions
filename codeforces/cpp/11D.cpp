#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, m;
vector<int> graph[20];
ll dp[19][(1 << 19)];

ll dfs(int node, int mask, int start)
{
    if (dp[node][mask] != -1)
        return dp[node][mask];

    ll res = 0;

    for (int child : graph[node])
    {
        if (child < start)
            continue;

        if (child == start && mask != ((1 << node) | (1 << child)))
            res++;

        if (child > start && (mask & (1 << child)) == 0)
            res += dfs(child, (mask | (1 << child)), start);
    }

    return dp[node][mask] = res;
}

void solve()
{
    int a, b;

    cin >> n >> m;

    REP(i, 1, m)
    {
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b), graph[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    ll ans = 0;

    REP(i, 0, n - 2)
    {
        ans += dfs(i, 1 << i, i);
    }

    cout << ans/2;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}