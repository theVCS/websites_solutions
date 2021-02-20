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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;

// initialization
vector<pii> tree[maxN];
int parent[maxN][20], subSize[maxN], level[maxN];
pii specialChild[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    level[node] = l;
    parent[node][0] = par;
    subSize[node] = 1;

    int sc = -1, size = 0, weight = 0;

    for (pii child : tree[node])
    {
        if (child.first == par)
            continue;

        dfs(child.first, node, l + 1);

        subSize[node] += subSize[child.first];

        if (size < subSize[child.first])
            size = subSize[child.first], sc = child.first, weight = child.second;
    }

    specialChild[node] = {sc, weight};
}

// heavy light decomposition
int chainHead[maxN], arr[maxN], label[maxN], timer;

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

// lCA finder
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

// kancestor finder
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

// segment tree portion
int segTree[4 * maxN];

void build(int si = 1, int ss = 1, int se = n)
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

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

int queryHLD(int node, int ances)
{
    int ans = 0, top = 0;

    while (level[node] > level[ances])
    {
        top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAnces(node, level[node] - level[ances] - 1);
        }

        ans += query(1, 1, n, label[top], label[node]);
        node = parent[top][0];
    }

    return ans;
}

// 0 -> white
// 1 -> black

int col[maxN];

struct path
{
    int dist, nodeA, nodeB;
};

set<path> ans;

int main(int argc, char const *argv[])
{
    int m, a, b, c, lca;

    scanf("%d", &n);

    REP(i, 1, n)
    {
        chainHead[i] = i;
        scanf("%d %d %d", &a, &b, &c);
        tree[a].push_back({b, c}), tree[b].push_back({a, c});
    }

    chainHead[n] = n;

    dfs();

    // preproessing for finding LCA
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

    HLD();
    build();

    scanf("%d", &m);
    string s;

    while (m--)
    {
        scanf("%s", s);

        if (s[0] == 'c')
        {
            scanf("%d", &a);
        }
    }

    return 0;
}