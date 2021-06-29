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
#define maxN 100001
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

int n;
struct range
{
    ll l, r;
} arr[maxN];

vector<int> graph[maxN];
ll val[maxN];
ll dp[maxN][3];

ll maxVal(int node, int par = -1, int t = 0)
{
    if (dp[node][t] != -1)
        return dp[node][t];

    ll ans1 = 0;
    val[node] = arr[node].l;

    if (par != -1)
    {
        ans1 = abs(val[node] - val[par]);
    }

    for (int child : graph[node])
    {
        if (child == par)
            continue;
        ans1 += maxVal(child, node, 1);
    }

    ll ans2 = 0;
    val[node] = arr[node].r;

    if (par != -1)
    {
        ans2 = abs(val[node] - val[par]);
    }

    for (int child : graph[node])
    {
        if (child == par)
            continue;
        ans2 += maxVal(child, node, 2);
    }

    return dp[node][t] = max(ans1, ans2);
}

void solve()
{
    int a, b;

    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i].l >> arr[i].r;
        graph[i].clear();
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }

    REP(i, 1, n - 1)
    {
        cin >> a >> b;
        graph[a].push_back(b), graph[b].push_back(a);
    }

    cout << maxVal(1) << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}