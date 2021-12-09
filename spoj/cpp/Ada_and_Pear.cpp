#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int treeNode = 50001;
vector<int> tree[treeNode];

// for lca finding
int level[treeNode], parent[treeNode][19];

// euler tree tour technique
int FT[2 * treeNode], intime[treeNode], outime[treeNode], timer;

class Tree
{
    int n;

public:
    Tree() {}

    Tree(int N)
    {
        n = N;
    }

    void resize(int N)
    {
        n = N;
    }

    void addEdge(int a, int b)
    {
        tree[a].push_back(b), tree[b].push_back(a);
    }

    void euler(int node = 1, int par = -1, int l = 0)
    {
        // euler tree tour technique
        intime[node] = ++timer;
        FT[timer] = node;

        // lca
        parent[node][0] = par;
        level[node] = l;

        for (int child : tree[node])
        {
            if (child == par)
                continue;
            euler(child, node, l + 1);
        }

        // euler tree tour technique
        outime[node] = ++timer;
        FT[timer] = node;
    }

    void init()
    {
        timer = 0;
        euler();

        // lca portion
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

int val[treeNode];
int rev[treeNode];
map<int, int> mp;

template <class T>
class FenwickTree
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree() {}

    FenwickTree(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    void resize(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    T query(int index)
    {
        T q = 0;

        while (index > 0)
        {
            q += BIT[index];
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] += val;
            index += (index & -index);
        }
    }

    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int lowerBound(T val)
    {
        // will find the lower bound index of val in BIT if monotonically increasing
        // https://codeforces.com/blog/entry/61364

        T q = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= n && q + BIT[pos + (1 << i)] < val)
            {
                q += BIT[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};

const int arrSize = 100001;
int nodeFre[treeNode];

template <class T>
class MO
{
    struct Query
    {
        int l, r, index, lca;
        ll order;

        Query(int _l, int _r, int _index, int _lca)
        {
            l = _l;
            r = _r;
            index = _index;
            lca = _lca;
            order = gilbertOrder(l, r, 21, 0);
        }

        inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
        {
            if (pow == 0)
            {
                return 0;
            }
            int hpow = 1 << (pow - 1);
            int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
            seg = (seg + rotate) & 3;
            const int rotateDelta[4] = {3, 0, 0, 1};
            int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
            int nrot = (rotate + rotateDelta[seg]) & 3;
            int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
            int64_t ans = seg * subSquareSize;
            int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
            ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
            return ans;
        }
    };

    int n, q;
    T res;
    vector<T> fre, ans;
    vector<Query> Q;
    FenwickTree<int> ft;

public:
    MO() {}

    // N -> no of elements, Q -> no of queries, R -> range of elements
    MO(int N, int Q, int R)
    {
        n = N;
        q = Q;
        res = 0;
        fre.assign(R + 1, 0);
        ans.resize(Q + 1);
        ft.resize(R + 1);
    }

    void resize(int N, int Q, int R)
    {
        n = N;
        q = Q;
        res = 0;
        fre.assign(R + 1, 0);
        ans.resize(Q + 1);
    }

    void addQuery(int l, int r, int index, int lca)
    {
        Q.push_back(Query(l, r, index, lca));
    }

    void add(int index)
    {
        int node = FT[index];
        int v = val[node];
        nodeFre[node]++;

        if (nodeFre[node] == 1)
        {
            // add
            ft.update(v, 1);
        }
        else if (nodeFre[node] == 2)
        {
            // remove
            ft.update(v, -1);
        }
    }

    void remove(int index)
    {
        int node = FT[index];
        int v = val[node];
        nodeFre[node]--;

        if (nodeFre[node] == 1)
        {
            // add
            ft.update(v, 1);
        }
        else if (nodeFre[node] == 0)
        {
            // remove
            ft.update(v, -1);
        }
    }

    void processQuery()
    {
        sort(all(Q), [](const Query &lhs, const Query &rhs)
             { return lhs.order < rhs.order; });

        for (int i = 0, L = 1, R = 0; i < q; i++)
        {
            while (R < Q[i].r)
                add(++R);
            while (L > Q[i].l)
                add(--L);
            while (R > Q[i].r)
                remove(R--);
            while (L < Q[i].l)
                remove(L++);

            if (Q[i].lca > 0)
                add(intime[Q[i].lca]);

            ans[Q[i].index] = rev[ft.lowerBound(ft.query(n)/2+1)];

            if (Q[i].lca > 0)
                remove(intime[Q[i].lca]);
        }
    }

    void showAns()
    {
        REP(i, 1, q)
        {
            cout << ans[i] << endl;
        }
    }
};

void solve()
{
    mp.clear();

    int n, m;
    cin >> n >> m;

    REP(i, 1, n)
    {
        cin >> val[i];
        mp[val[i]];
        nodeFre[i] = 0;
        tree[i].clear();
    }

    int timer = 0;

    for (auto &e : mp)
        e.second = ++timer, rev[timer] = e.first;

    REP(i, 1, n)
    val[i] = mp[val[i]];

    Tree tree(n);

    REP(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        tree.addEdge(a + 1, b + 1);
    }

    tree.init();
    MO<int> mo(n, m, n);

    REP(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        a++, b++;

        if (intime[a] > intime[b])
            swap(a, b);

        int lca = tree.LCA(a, b);

        if (lca == a)
            mo.addQuery(intime[a], intime[b], i, -1);
        else
            mo.addQuery(outime[a], intime[b], i, lca);
    }

    mo.processQuery();
    mo.showAns();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}