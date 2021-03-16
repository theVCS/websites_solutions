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

int n;
vector<int> arr[maxN];

int intime[maxN], outime[maxN], FT[2 * maxN], timer;
int parent[maxN][18], level[maxN];
void dfs(int node = 1, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    FT[timer] = node;
    parent[node][0] = par;
    level[node] = l;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node, l + 1);
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

int segTree[maxN * 8], lazy[8 * maxN];

int query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return INT_MIN;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return max(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qs, int qe, int v)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] += v;

        if (ss != se)
            lazy[2 * si] += v, lazy[2 * si + 1] += v;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, v);
    update(2 * si + 1, mid + 1, se, qs, qe, v);
    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
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

    for (int i = 17; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int kAnces(int a, int d)
{
    while (d > 0)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    return a;
}

void solve()
{
    int a, b;
    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs();

    for (int j = 1; j < 18; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
                parent[i][j] = -1;
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    string s;
    int q;

    cin >> q;

    while (q--)
    {
        cin >> s >> a >> b;

        if (s[0] == 'a')
        {
            update(1, 1, timer, intime[a], outime[a], b);
        }
        else
        {
            int lca = LCA(a, b);
            int nodea, nodeb;

            nodea = kAnces(a, level[a] - level[lca] - 1);
            nodeb = kAnces(b, level[b] - level[lca] - 1);

            cout << max({query(1, 1, timer, intime[nodea], intime[a]), query(1, 1, timer, intime[nodeb], intime[b]), query(1, 1, timer, intime[lca], intime[lca])}) << endl;
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}