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

vector<int> tree[maxN];
ll cost[maxN];
int parent[maxN][20], level[maxN], subSize[maxN], specialChild[maxN], n;

void dfs(int node = 1, int par = -1, int l = 0)
{
    parent[node][0] = par;
    level[node] = l;
    subSize[node] = 1;

    int nodeX = -1, size = 0;

    for (int child : tree[node])
    {
        if (child == par)
            continue;

        dfs(child, node, l + 1);

        subSize[node] += subSize[child];

        if (size < subSize[child])
            size = subSize[child], nodeX = child;
    }

    specialChild[node] = nodeX;
}

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

// LCA finder
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
            a = parent[a][i], b = parent[b][i];
    }

    return parent[a][0];
}

// k-th ancestor finder
int kAncestor(int a, int d)
{
    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    return a;
}

int timer, label[maxN];
ll arr[maxN];
int chainHead[maxN];

void HLD(int node = 1, int par = -1)
{
    label[node] = ++timer;
    arr[timer] = cost[node];

    int sc = specialChild[node];

    if (sc != -1)
    {
        chainHead[sc] = chainHead[node];
        HLD(sc, node);
    }

    for (int child : tree[node])
    {
        if (child == sc || child == par)
            continue;
        HLD(child, node);
    }
}

ll segTree[maxN * 4];
int lazy[maxN * 4];

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
        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        if (lazy[si] % 2)
            segTree[si] = (se - ss + 1) * 1LL * 2147483647 - segTree[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        if (lazy[si] % 2)
            segTree[si] = (se - ss + 1) * 1LL * 2147483647 - segTree[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] = (se - ss + 1) * 1LL * 2147483647 - segTree[si];

        if (ss != se)
            lazy[2 * si] += 1, lazy[2 * si + 1] += 1;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);

    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

ll queryHl(int node, int ances)
{
    ll res = 0;
    int top = 0;

    while (level[node] > level[ances])
    {
        top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAncestor(node, level[node] - level[ances] - 1);
        }

        res += query(1, 1, n, label[top], label[node]);
        node = parent[top][0];
    }

    return res;
}

void updateHl(int node, int ances)
{
    int top = 0;

    while (level[node] > level[ances])
    {
        top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAncestor(node, level[node] - level[ances] - 1);
        }

        update(1, 1, n, label[top], label[node]);
        node = parent[top][0];
    }
}

void solve()
{
    int q, a, b, code;

    cin >> n >> q;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        tree[a].push_back(b), tree[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        cin >> cost[i];
        chainHead[i] = i;
    }

    init();
    HLD();
    build(1, 1, n);

    while (q--)
    {
        cin >> code >> a >> b;

        if (code == 1)
        {
            int lca = LCA(a, b);

            updateHl(a, lca);
            updateHl(b, lca);
            update(1, 1, n, label[lca], label[lca]);
        }
        else
        {
            int lca = LCA(a, b);
            cout << queryHl(a, lca) + queryHl(b, lca) + query(1, 1, n, label[lca], label[lca]) << endl;
        }
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

    // cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}