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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;

struct edges
{
    int u, v, w, index;
} edge[maxN];

bool cmp(edges a, edges b)
{
    return a.w < b.w;
}

// now making mst
vector<pii> tree[maxN];
int par[maxN];

int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    if (par[a] > par[b])
        swap(a, b);

    par[a] += par[b];
    par[b] = a;
}
// formed tree upto this point now going to apply hld now

// I. applying dfs on tree
int subSize[maxN], parent[maxN][20], level[maxN];
pair<int, int> specialChild[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    level[node] = l;
    parent[node][0] = par;
    subSize[node] = 1;

    int sc = -1, wt = 0, mxSize = 0;

    for (pii child : tree[node])
    {
        if (child.first == par)
            continue;
        dfs(child.first, node, l + 1);
        subSize[node] += subSize[child.first];

        if (subSize[child.first] > mxSize)
        {
            mxSize = subSize[child.first], sc = child.first, wt = child.second;
        }
    }

    specialChild[node] = {sc, wt};
}

// dyanmically initializing the parent arrar
void init()
{
    dfs();

    for (int j = 1; j < 20; j++)
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

// finding lca
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

    for (int i = 19; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

// element shifter
int kAnces(int a, int d)
{
    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    return a;
}

// applying HLD on tree
int chainHead[maxN], label[maxN], arr[maxN], timer;

void HLD(int node = 1, int par = -1, int val = 0)
{
    label[node] = timer;
    arr[timer++] = val;

    int sc = specialChild[node].first;

    if (sc != -1)
    {
        chainHead[sc] = chainHead[node];
        HLD(sc, node, specialChild[node].second);
    }

    for (pii child : tree[node])
    {
        if (child.first == par || child.first == sc)
            continue;
        HLD(child.first, node, child.second);
    }
}

// now building segment tree
int segTree[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return max(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

// writing query for hld tree
int queryHLD(int node, int ances)
{
    int res = 0;

    while (level[node] > level[ances])
    {
        int top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAnces(node, level[node] - level[ances] - 1);
        }

        res = max(res, query(1, 1, n, label[top], label[node]));
        node = parent[top][0];
    }

    return res;
}

ll ans[maxN];

void solve()
{
    int m, a, b, c;

    ll res = 0;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        par[i] = -1;
        chainHead[i] = i;
    }

    REP(i, 0, m)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].index = i;
    }

    sort(edge, edge + m, cmp);

    REP(i, 0, m)
    {
        int a = find(edge[i].u);
        int b = find(edge[i].v);

        if (a == b)
            continue;

        merge(a, b);

        tree[a].push_back({b, edge[i].w});
        tree[b].push_back({a, edge[i].w});

        res = res + edge[i].w * 1LL;
    }

    init();
    HLD();
    build(1, 1, n);

    REP(i, 0, m)
    {
        int lca = LCA(edge[i].u, edge[i].v);
        ll tempAns = max(queryHLD(edge[i].u, lca), queryHLD(edge[i].v, lca));
        ans[edge[i].index] = res - tempAns + edge[i].w * 1LL;
    }

    REP(i, 0, m)
        cout << ans[i] << endl;
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