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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
ll nodeVal[maxN];
vector<int> tree[maxN];
int level[maxN], specialChild[maxN], parent[maxN][20], subSize[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    parent[node][0] = par;
    level[node] = l;
    subSize[node] = 1;

    int sc = -1, size = 0;

    for (int child : tree[node])
    {
        if (child == par)
            continue;

        dfs(child, node, l + 1);

        subSize[node] += subSize[child];

        if (size < subSize[child])
            size = subSize[child], sc = child;
    }

    specialChild[node] = sc;
}

ll arr[maxN];
int label[maxN], timer, chainHead[maxN];

void HLD(int node = 1, int par = -1)
{
    arr[++timer] = nodeVal[node];
    label[node] = timer;

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

ll segTree[4 * maxN];

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
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;

        if (qi <= mid)
            update(2 * si, ss, mid, qi);
        else
            update(2 * si + 1, mid + 1, se, qi);

        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
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

ll queryHLD(int node, int ances)
{
    ll res = 0;
    int top = 0;

    while (level[node] > level[ances])
    {
        top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAnces(node, level[node] - level[ances] - 1);
        }

        res += query(1, 1, n, label[top], label[node]);
        node = parent[top][0];
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, code;
    ll a, b;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        cin >> nodeVal[i];
        chainHead[i] = i;
    }

    REP(i, 1, n)
    {
        cin >> a >> b;
        tree[a].push_back(b), tree[b].push_back(a);
    }

    dfs();

    // lca preprocessing
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

    while (m--)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> a >> b;
            arr[label[a]] = b;
            nodeVal[a] = b;
            update(1, 1, n, label[a]);
        }
        else
        {
            cin >> a;
            cout << (queryHLD(a, 1) + nodeVal[1]) << endl;
        }
    }

    return 0;
}
