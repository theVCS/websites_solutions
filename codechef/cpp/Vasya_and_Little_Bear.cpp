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

struct node
{
    int n, h;
};

const int blk = 700;

// initialization
vector<int> arr[maxN];
int col[maxN], h[maxN];
int parent[maxN][21], level[maxN];

// flattening the tree
int FT[2 * maxN], intime[maxN], outime[maxN], timer;

// processing queries
int nodeFre[maxN];
deque<node> colArr[11];

// storing result
ll ans[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    FT[timer] = node;
    level[node] = l;
    parent[node][0] = par;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, l + 1);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

void init(int n)
{
    dfs();

    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
            {
                parent[i][j] = -1;
            }
            else
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
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

    for (int i = 20; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i], b = parent[b][i];
        }
    }

    return parent[a][0];
}

struct query
{
    int l, r, lca, index;
} Q[10001];

bool cmp(query a, query b)
{
    int x = a.l / blk, y = b.l / blk;
    return (x < y) || (x == y && a.r < b.r);
}

void add(int index, bool right)
{
    int node = FT[index];
    int c = col[node];

    nodeFre[node]++;

    if (nodeFre[node] == 1)
    {
        if (right)
        {
            colArr[c].push_back({node, h[node]});
        }
        else
        {
            colArr[c].push_front({node, h[node]});
        }
    }
    else if (nodeFre[node] == 2)
    {
        if (right)
        {
            colArr[c].pop_back();
        }
        else
        {
            colArr[c].pop_front();
        }
    }
}

void remove(int index, bool right)
{
    int node = FT[index];
    int c = col[node];

    nodeFre[node]--;

    if (nodeFre[node] == 1)
    {
        if (right)
        {
            colArr[c].push_back({node, h[node]});
        }
        else
        {
            colArr[c].push_front({node, h[node]});
        }
    }
    else if (nodeFre[node] == 0)
    {
        if (right)
        {
            colArr[c].pop_back();
        }
        else
        {
            colArr[c].pop_front();
        }
    }
}

void getAns(int index, int lca)
{
    int i = 1;

    while (i <= 10)
    {
        if (i == col[lca])
        {
            i++;
            continue;
        }

        for (int j = 1; j < colArr[i].size(); j++)
        {
            ans[index] += 1LL * (colArr[i][j].h - colArr[i][j - 1].h) * (colArr[i][j].h - colArr[i][j - 1].h);
        }

        i++;
    }
}

void printer()
{
    REP(j, 1, 11)
    {
        cout << j << " --> ";
        for (node child : colArr[j])
            cout << child.n << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m, a, b;

    // scanf("%d", &n);
    cin >> n;

    REP(i, 1, n + 1)
    // scanf("%d", col + i);
    cin >> col[i];

    REP(i, 1, n + 1)
    // scanf("%d", h + i);
    cin >> h[i];

    REP(i, 0, n - 1)
    {
        // scanf("%d %d", &a, &b);
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    init(n);

    // scanf("%d", &m);
    cin >> m;

    REP(i, 1, m + 1)
    {
        // scanf("%d %d", &a, &b);
        cin >> a >> b;

        if (intime[a] > intime[b])
            swap(a, b);

        int lca = LCA(a, b);

        if (lca == a) // first type of query
        {
            Q[i].l = intime[a];
        }
        else
        {
            Q[i].l = outime[a];
        }

        Q[i].lca = lca;
        Q[i].index = i;
        Q[i].r = intime[b];
    }

    sort(Q + 1, Q + 1 + m, cmp);

    for (int i = 1, L = 1, R = 0; i < m + 1; i++)
    {
        while (L < Q[i].l)
            remove(L++, false);
        while (L > Q[i].l)
            add(--L, false);
        while (R < Q[i].r)
            add(++R, true);
        while (R > Q[i].r)
            remove(R--, true);

        // printer();

        getAns(Q[i].index, Q[i].lca);
    }

    REP(i, 1, m + 1)
    printf("%lld\n", ans[i]);

    return 0;
}