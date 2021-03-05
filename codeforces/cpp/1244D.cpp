#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct colCost
{
    ll cost1, cost2, cost3;

    ll cost(int i)
    {
        if (i == 1)
            return cost1;
        if (i == 2)
            return cost2;
        if (i == 3)
            return cost3;
    }

} col[maxN];

vector<int> arr[maxN];
int parent[maxN], ans[maxN];
int endNode;

void dfs(int node, int par = 0)
{
    parent[node] = par;
    bool flag = true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
        flag = false;
    }

    if (flag)
        endNode = node;
}

void solve()
{
    int n, a, b;

    cin >> n;

    REP(i, 1, n + 1)
    cin >> col[i].cost1;
    REP(i, 1, n + 1)
    cin >> col[i].cost2;
    REP(i, 1, n + 1)
    cin >> col[i].cost3;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);

        if (arr[a].size() > 2 || arr[b].size() > 2)
        {
            cout << -1;
            return;
        }
    }

    int start;

    REP(i, 1, n + 1)
    {
        if (arr[i].size() < 2)
        {
            start = i;
            break;
        }
    }

    dfs(start);
    ll res = __LONG_LONG_MAX__;
    int pos;
    int node;
    int colVar[3][2][3];
    ll instCost;
    int resI, resVar;

    // there are six kind of variations
    colVar[0][0][0] = 1, colVar[0][0][1] = 2, colVar[0][0][2] = 3;
    colVar[0][1][0] = 1, colVar[0][1][1] = 3, colVar[0][1][2] = 2;
    colVar[1][0][0] = 2, colVar[1][0][1] = 3, colVar[1][0][2] = 1;
    colVar[1][1][0] = 2, colVar[1][1][1] = 1, colVar[1][1][2] = 3;
    colVar[2][0][0] = 3, colVar[2][0][1] = 2, colVar[2][0][2] = 1;
    colVar[2][1][0] = 3, colVar[2][1][1] = 1, colVar[2][1][2] = 2;

    REP(i, 0, 3)
    {
        REP(var, 0, 2)
        {
            node = endNode;
            instCost = 0;
            pos = 0;

            while (node)
            {
                instCost += col[node].cost(colVar[i][var][pos]);
                node = parent[node];
                pos = (pos + 1) % 3;
            }

            if (res > instCost)
            {
                res = instCost;
                resI = i;
                resVar = var;
            }
        }
    }

    cout << res << endl;
    pos = 0;

    while (endNode)
    {
        ans[endNode] = colVar[resI][resVar][pos];
        endNode = parent[endNode];
        pos = (pos + 1) % 3;
    }

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