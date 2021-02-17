#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;

// intiliazation
vector<pii> tree[maxN];
int parent[maxN][20], level[maxN], subSize[maxN];
pii specialChild[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    level[node] = l;
    parent[node][0] = par;
    subSize[node] = 1;

    int nodeX = -1, size = 0, weight = 0;

    for (pii child : tree[node])
    {
        if (child.first == par)
            continue;

        dfs(child.first, node, l + 1);

        if (subSize[child.first] > size)
            size = subSize[child.first], nodeX = child.first, weight = child.second;

        subSize[node] += subSize[child.first];
    }

    specialChild[node] = {nodeX, weight};
}

// heavy light decomposition
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

// LCA FINDER
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

// K-th ancestor finder
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

// basic segment tree
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

int queryHL(int node, int ances)
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

int main(int argc, char const *argv[])
{
    int t, a, b, c, lca;
    char s[100];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        timer = 0;
        REP(i, 0, n + 1)
        {
            tree[i].clear();
            chainHead[i] = i;
        }

        REP(i, 1, n)
        {
            scanf("%d %d %d", &a, &b, &c);
            tree[a].push_back({b, c}), tree[b].push_back({a, c});
        }

        dfs();

        // binary lifting preprocessing
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
        build(1, 1, n);

        // REP(i, 1, n + 1)
        // cout << i << " -> " << chainHead[i] << endl;

        while (true)
        {
            scanf("%s", s);

            if (s[1] == 'O')
                break;

            if (s[1] == 'I')
            {
                scanf("%d %d", &a, &b);
                lca = LCA(a, b);
                printf("%d\n", queryHL(a, lca) + queryHL(b, lca));
            }
            else
            {
                scanf("%d %d %d", &a, &b, &c);
                lca = LCA(a, b);

                int dist = level[a] + level[lca] - 2 * level[lca];

                if (c == dist + 1)
                {
                    printf("%d\n", lca);
                }
                else if (c < dist + 1)
                {
                    printf("%d\n", kAnces(a, c - 1));
                }
                else
                {
                    c -= dist + 1;
                    dist = level[b] + level[lca] - 2 * level[lca];
                    c = dist - c + 1;
                    printf("%d\n", kAnces(b, c - 1));
                }
            }
        }
    }

    return 0;
}