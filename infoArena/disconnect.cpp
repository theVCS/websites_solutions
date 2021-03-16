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

vector<int> arr[maxN];
int parent[maxN][17], level[maxN], subSize[maxN];
int specialChild[maxN], n;

void dfs(int node, int par = -1, int l = 0)
{
    level[node] = l;
    parent[node][0] = par;
    subSize[node] = 1;

    int mxSize = 0, nodeX = -1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node, l + 1);

        subSize[node] += subSize[child];

        if (subSize[child] > mxSize)
            mxSize = subSize[child], nodeX = child;
    }

    specialChild[node] = nodeX;
}

void init()
{
    dfs(1);

    for (int j = 1; j < 17; j++)
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

    for (int i = 16; i >= 0; i--)
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
    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    return a;
}

// applying hld
int label[maxN], chainHead[maxN], timer;

void HLD(int node = 1, int par = -1)
{
    label[node] = ++timer;

    if (specialChild[node] != -1)
    {
        chainHead[specialChild[node]] = chainHead[node];
        HLD(specialChild[node], node);
    }

    for (int child : arr[node])
    {
        if (child == par || child == specialChild[node])
            continue;
        HLD(child, node);
    }
}

// making segment tree
int segTree[4 * maxN];

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si]++;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

int queryHLD(int node, int lca)
{
    int res = 0;

    while (level[node] > level[lca])
    {
        int top = chainHead[node];

        if (level[top] <= level[lca])
        {
            top = kAnces(node, level[node] - level[lca] - 1);
        }

        res += query(1, 1, n, label[top], label[node]);
        node = parent[top][0];
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ifstream fi("disconnect.in");
    ofstream fo("disconnect.out");

    // fi >> input;
    // fo << output;

    int code, m, a, b;

    fi >> n >> m;

    REP(i, 1, n)
    {
        fi >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
        chainHead[i] = i;
    }
    chainHead[n] = n;

    init();
    HLD(1);

    int v = 0;

    while (m--)
    {
        fi >> code >> a >> b;

        a = a ^ v;
        b = b ^ v;

        if (code == 1)
        {
            if (level[a] < level[b])
                swap(a, b);
            update(1, 1, n, label[a]);
        }
        else
        {
            int lca = LCA(a, b);
            int res = queryHLD(a, lca) + queryHLD(b, lca);

            if (res == 0)
            {
                fo << "YES" << endl;
                v = a;
            }
            else
            {
                fo << "NO" << endl;
                v = b;
            }
        }
    }

    fi.close();
    fo.close();

    return 0;
}