#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x

const int treeNode = 100001;
vector<int> tree[treeNode];
int level[treeNode], parent[treeNode][19];
int arr[2 * treeNode], intime[treeNode], outime[treeNode], timer;
ll weight[treeNode];
int rev[treeNode];
class Tree
{
    int n;

public:
    Tree() {}
    Tree(int N) { n = N; }
    void resize(int N) { n = N; }
    void addEdge(int a, int b) { tree[a].push_back(b), tree[b].push_back(a); }
    void euler(int node = 1, int par = -1, int l = 0)
    {
        intime[node] = ++timer;
        arr[timer] = node;
        parent[node][0] = par;
        level[node] = l;
        for (int child : tree[node])
        {
            if (child == par)
                continue;
            euler(child, node, l + 1);
        }
        outime[node] = ++timer;
        arr[timer] = node;
    }
    void init()
    {
        euler();
        for (int j = 1; j < 19; j++)
            for (int i = 1; i <= n; i++)
                if (parent[i][j - 1] == -1)
                    parent[i][j] = -1;
                else
                    parent[i][j] = parent[parent[i][j - 1]][j - 1];
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
        for (int i = 18; i >= 0; i--)
            if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
                a = parent[a][i], b = parent[b][i];
        return parent[a][0];
    }
};
template <class T>
class PersistentSegmentTree
{
    int n;
    vector<T> segTree;
    vector<int> left, right;
    vector<int> roots;
    int index;

public:
    PersistentSegmentTree() {}
    int build(int ss, int se)
    {
        int node = ++index;
        if (ss == se)
        {
            segTree[node] = 0;
            return node;
        }
        else
        {
            int mid = (ss + se) / 2;
            left[node] = build(ss, mid);
            right[node] = build(mid + 1, se);
            segTree[node] = 0;
            return node;
        }
    }
    PersistentSegmentTree(int N)
    {
        n = N;
        segTree.resize(N * 21);
        left.resize(N * 21);
        right.resize(N * 21);
        index = 0;
        roots.push_back(build(1, n));
    }
    void resize(int N)
    {
        n = N;
        segTree.resize(N * 21);
        left.resize(N * 21);
        right.resize(N * 21);
        index = 0;
        roots.push_back(build(1, n));
    }
    int _update_(int prevNode, int ss, int se, int qi, T val)
    {
        int node = ++index;
        if (ss == se)
        {
            segTree[node] = segTree[prevNode] + val;
            return node;
        }
        int mid = (ss + se) / 2;
        if (qi <= mid)
        {
            right[node] = right[prevNode];
            left[node] = _update_(left[prevNode], ss, mid, qi, val);
        }
        else
        {
            left[node] = left[prevNode];
            right[node] = _update_(right[prevNode], mid + 1, se, qi, val);
        }
        segTree[node] = segTree[left[node]] + segTree[right[node]];
        return node;
    }
    void update(int index, T val) { roots.push_back(_update_(roots.back(), 1, n, index, val)); }
    T _query_(int nodeA, int nodeB, int ss, int se, int qs, int qe)
    {
        if (qs > se || qe < ss)
            return 0;
        if (qs <= ss && qe >= se)
            return segTree[nodeA] - segTree[nodeB];
        int mid = (ss + se) / 2;
        return _query_(left[nodeA], left[nodeB], ss, mid, qs, qe) + _query_(right[nodeA], right[nodeB], mid + 1, se, qs, qe);
    }
    T _query_(int nodeA, int nodeB, int ss, int se, int k)
    {
        if (ss == se)
            return ss;
        int diff = segTree[left[nodeA]] - segTree[left[nodeB]];
        int mid = (ss + se) / 2;
        if (diff >= k)
            return _query_(left[nodeA], left[nodeB], ss, mid, k);
        else
            return _query_(right[nodeA], right[nodeB], mid + 1, se, k - diff);
    }
    T _query_(int nodeA, int nodeB, int nodeC, int nodeD, int ss, int se, int k)
    {
        if (ss == se)
            return ss;
        int mid = (ss + se) / 2;
        int diff = segTree[left[nodeA]] + segTree[left[nodeC]] - segTree[left[nodeB]] - segTree[left[nodeD]];
        if (diff >= k)
            return _query_(left[nodeA], left[nodeB], left[nodeC], left[nodeD], ss, mid, k);
        else
            return _query_(right[nodeA], right[nodeB], right[nodeC], right[nodeD], mid + 1, se, k - diff);
    }
    T query(int ul, int ur, int k) { return _query_(roots[ur], roots[ul - 1], 1, n, k); }
    T query(int ul1, int ur1, int ul2, int ur2, int k) { return _query_(roots[ur1], roots[ul1 - 1], roots[ur2], roots[ul2 - 1], 1, n, k); }
};
int fre[treeNode];
void solve()
{
    int n, m;
    cin >> n >> m;
    map<ll, int> mp;
    REP(i, 1, n)
    cin >> weight[i],
        mp[weight[i]];
    int t = 0;
    for (auto &e : mp)
        e.second = ++t, rev[t] = e.first;
    REP(i, 1, n)
    weight[i] = mp[weight[i]];
    Tree tree(n);
    REP(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        tree.addEdge(a, b);
    }
    tree.init();
    PersistentSegmentTree<int> segTree(timer);
    REP(i, 1, timer)
    {
        int node = arr[i];
        if (++fre[node] == 1)
            segTree.update(weight[node], 1);
        else
            segTree.update(weight[node], -1);
    }
    REP(i, 1, m)
    {
        int a, b, k;
        cin >> a >> b >> k;
        if (intime[a] > intime[b])
            swap(a, b);
        int lca = tree.LCA(a, b);
        if (lca == a)
            cout << rev[segTree.query(intime[a], intime[b], k)] << endl;
        else
            cout << rev[segTree.query(intime[lca], intime[a], intime[lca] + 1, intime[b], k)] << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}