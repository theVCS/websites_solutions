#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pil pair<int, ll>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
#define INF 0x3f3f3f3f
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

struct edge
{
    int u, v;
    ll wt;
};

bool cmp(edge a, edge b)
{
    return a.wt < b.wt;
}

vector<edge> arr;
int par[maxN];

int find(int a)
{
    if (par[a] < 0)
        return a;
    else
        return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    if (par[a] > par[b])
        swap(a, b);

    par[a] += par[b];
    par[b] = a;
}

vector<pil> tree[maxN];
int parent[maxN][11], level[maxN];
map<ll, map<int, int>> mp;

void dfs(int node, int par = -1, int l = 0)
{
    level[node] = l;
    parent[node][0] = par;

    for (pil child : tree[node])
    {
        if (child.first == par)
            continue;

        dfs(child.first, node, l + 1);

        mp[node][child.first] = child.second;

        for (auto ele : mp[child.first])
        {
            mp[node][ele.first] = ele.second + child.second;
        }
    }
}

void init(int n)
{
    dfs(1);

    for (int j = 1; j < 11; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
                parent[i][j] = -1;
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 10; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

void solve()
{
    arr.clear();
    mp.clear();

    int n, a, b;
    ll wt;

    cin >> n;

    REP(i, 1, n + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> wt;

            if (i < j)
            {
                edge e;
                e.u = i, e.v = j, e.wt = wt;
                arr.push_back(e);
            }
        }

        par[i] = -1;
        tree[i].clear();
    }

    sort(all(arr), cmp);

    for (edge e : arr)
    {
        a = find(e.u);
        b = find(e.v);

        if (a == b)
            continue;

        merge(a, b);

        tree[a].push_back({b, e.wt});
        tree[b].push_back({a, e.wt});
    }

    init(n);

    for (auto e : mp[2])
    {
        cout << e.first << " " << e.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}