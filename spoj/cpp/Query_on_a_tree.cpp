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

// initialization part
int level[maxN], parent[maxN][20], subSize[maxN];
vector<pii> tree[maxN]; // will store the tree
vector<int> edge[maxN]; // will store the ith edge
pii specialChild[maxN]; // this array will store the special child of a node with the child and weight of edge from node to child(first is a child and second is the weight of edge)

// dfs call to find out level, parent, subTree size and special child for each node
void dfs(int node = 1, int par = -1, int l = 0)
{
    parent[node][0] = par;
    level[node] = l;
    subSize[node] = 1;

    int nodeX = -1, size = 0, weight = 0;

    for (pii child : tree[node])
    {
        if (child.first == par)
            continue;

        dfs(child.first, node, l + 1);

        subSize[node] += subSize[child.first];

        if (size < subSize[child.first])
            size = subSize[child.first], nodeX = child.first, weight = child.second;
    }

    specialChild[node] = {nodeX, weight};
}

// heavy light decomposition
int timer, label[maxN], arr[maxN], chainHead[maxN];
// chainHead will store the head of each chain
// arr shall store the list of weight for edge between node and parent of node
// label shall store the index for a particular node

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

// segment tree -- normal segment tree implementation
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
        node = parent[top][0];
    }

    return res;
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
            chainHead[i] = i;
            edge[i].clear();
            tree[i].clear();
        }

        REP(i, 1, n)
        {
            scanf("%d %d %d", &a, &b, &c);
            tree[a].push_back({b, c}), tree[b].push_back({a, c});
            edge[i].push_back(a), edge[i].push_back(b);
        }

        dfs();

        // dp on parent array -- binary lifting preprocessing
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
        build(1, 1, n); // build segment tree

        while (true)
        {
            scanf("%s", s);

            if (s[0] == 'D')
                break;

            scanf("%d %d", &a, &b);

            if (s[0] == 'Q')
            {
                lca = LCA(a, b);
                printf("%d\n", max(queryHl(a, lca), queryHl(b, lca))); // broken query in two parts
            }
            else
            {
                int index;

                if (level[edge[a][0]] > level[edge[a][1]])
                    index = label[edge[a][0]];
                else
                    index = label[edge[a][1]];

                arr[index] = b;
                update(1, 1, n, index); // uodated in accordance with the node connected in ith edge
            }
        }
    }

    return 0;
}