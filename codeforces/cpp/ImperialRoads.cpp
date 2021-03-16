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
#define INF 0x3f3f3f3f
#define endl "\n"
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

struct edges
{
    int u, v, wt;
} edge[maxN];

int n;

bool cmp(edges a, edges b)
{
    return a.wt < b.wt;
}

int parent[maxN];
vector<pii> graph[maxN];

int find(int a)
{
    if (parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    if (parent[a] > parent[b])
        swap(a, b);

    parent[a] += parent[b];
    parent[b] = a;
}

// formed tree uptill this point now applying heavy light decomposition
vector<pii> tree[maxN];
int par[maxN][20], subSize[maxN], level[maxN];
pii specialChild[maxN];

void dfs(int node, int p = -1, int l = 0)
{
    par[node][0] = p;
    level[node] = l;
    subSize[node] = 1;

    int nodeX = -1, size = 0, weight = 0;

    for (pii child : tree[node])
    {
        if (child.first == p)
            continue;

        dfs(child.first, node, l + 1);

        subSize[node] += subSize[child.first];

        if (size < subSize[child.first])
            size = subSize[child.first], nodeX = child.first, weight = child.second;
    }

    specialChild[node] = {nodeX, weight};
}

int timer, label[maxN], arr[maxN], chainHead[maxN];

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
        if (child.first == sc || child.first == par)
            continue;
        HLD(child.first, node, child.second);
    }
}

int segTree[maxN * 4];

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

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

// LCA finder
int LCA(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = par[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--)
    {
        if (par[a][i] != -1 && par[a][i] != par[b][i])
            a = par[a][i], b = par[b][i];
    }

    return par[a][0];
}

// k-th ancestor finder
int kAncestor(int a, int d)
{
    while (d)
    {
        int i = log2(d);
        a = par[a][i];
        d -= 1 << i;
    }

    return a;
}

// will give answer for the given query between node and ancestor
int queryHl(int node, int ances)
{
    int res = 0, top = 0;

    while (level[node] > level[ances])
    {
        top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAncestor(node, level[node] - level[ances] - 1);
        }

        res = max(res, query(1, 1, n, label[top], label[node]));
        node = par[top][0];
    }

    return res;
}
void solve()
{
    int r, m, a, b, c, lca;
    ll res = 0, temp1 = 0, temp2;

    cin >> n >> r;

    REP(i, 0, n + 1)
    {
        parent[i] = -1;
        chainHead[i] = i;
    }

    REP(i, 0, r)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].wt;
        graph[edge[i].u].push_back({edge[i].v, edge[i].wt});
        graph[edge[i].v].push_back({edge[i].u, edge[i].wt});
    }

    sort(edge, edge + r, cmp);

    for (edges e : edge)
    {
        int a = find(e.u);
        int b = find(e.v);

        if (a == b)
            continue;

        merge(a, b);
        tree[a].push_back({b, e.wt}), tree[b].push_back({a, e.wt});
        res += e.wt * 1LL;
    }

    dfs(1);

    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (par[i][j - 1] == -1)
                par[i][j] = -1;
            else
                par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }

    HLD();
    build(1, 1, n);

    int q;

    cin >> q;

    while (q--)
    {
        cin >> a >> b;
        lca = LCA(a, b);
        temp1 = max(queryHl(a, lca), queryHl(b, lca));

        for (pii child : graph[a])
        {
            if (child.first == b)
            {
                temp2 = child.second;
                break;
            }
        }

        cout << res - temp1 + temp2 << endl;
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}