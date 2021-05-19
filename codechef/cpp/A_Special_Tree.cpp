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
#define maxN 200001
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

int n, k, a;
bool special[maxN];
vector<int> arr[maxN];
int spe_node[maxN];
int parent[maxN], level[maxN];
int ans[maxN];

int dfs(int node, int par = -1, int lev = 0)
{
    level[node] = lev;
    parent[node] = par;
    int sp = -1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        int temp = -1;
        temp = dfs(child, node, lev + 1);

        if (temp != -1)
            sp = temp;
    }

    if (special[node])
        sp = node;

    if (sp != -1)
    {
        spe_node[node] = sp;
        ans[node] = level[node];
    }

    return sp;
}

void dfs2(int node, int pivot, int dep = 1)
{
    spe_node[node] = spe_node[pivot];
    ans[node] = ans[pivot] - dep;

    for (int child : arr[node])
    {
        if (child == parent[node])
            continue;
        dfs2(child, pivot, dep + 1);
    }
}

void solve()
{
    int u, v;

    cin >> n >> k >> a;

    REP(i, 1, n)
    {
        arr[i].clear();
        special[i] = false;
        ans[i] = -1;
    }

    REP(i, 1, k)
    {
        cin >> u;
        special[u] = true;
    }

    REP(i, 1, n - 1)
    {
        cin >> u >> v;
        arr[u].push_back(v), arr[v].push_back(u);
    }

    dfs(a);

    REP(node, 1, n)
    {
        if (ans[node] == -1 && parent[node] != -1 && ans[parent[node]] != -1)
        {
            dfs2(node, parent[node]);
        }
    }

    REP(i, 1, n)
    cout << ans[i] << " ";
    cout << endl;
    REP(i, 1, n)
    cout << spe_node[i] << " ";
    cout << endl;
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