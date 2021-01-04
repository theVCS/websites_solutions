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
#define endl '\n'
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, q, val[maxN];
vector<int> arr[maxN];
int intime[maxN], outime[maxN], parent[maxN][21], level[maxN], timer, FT[2 * maxN], ML, MR;
int ans[2 * maxN], fre[maxN], valfre[maxN];
const int blk = 700;

void dfs(int node = 1, int par = -1, int lev = 0)
{
    parent[node][0] = par;
    level[node] = lev;
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, lev + 1);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

void init()
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
    {
        swap(a, b);
    }
    int i, d = level[a] - level[b];

    while (d)
    {
        i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
    {
        return a;
    }

    for (int i = 20; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

struct query
{
    int l, r, ind, lca, c;
};
query Q[200001];

bool cmp(query a, query b)
{
    int x = a.l / blk;
    int y = b.l / blk;

    if (x != y)
    {
        return x < y;
    }

    if (x % 2)
    {
        return a.r > b.r;
    }
    return a.r < b.r;
}

void add(int ind)
{
    int node = FT[ind];
    int v = val[node];
    fre[node]++;

    if (fre[node] == 1)
    {
        valfre[v]++;
    }
    else
    {
        valfre[v]--;
    }
}

void remove(int ind)
{
    int node = FT[ind];
    int v = val[node];
    fre[node]--;

    if (fre[node] == 1)
    {
        valfre[v]++;
    }
    else
    {
        valfre[v]--;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0, a, b, c, lca, L, R;

    while (cin >> n)
    {
        if (t)
        {
            cout << endl;
        }
        t++;

        cin >> q;

        timer = 0;
        valfre[0] = 0;

        REP(i, 1, n + 1)
        {
            arr[i].clear(), fre[i] = 0, valfre[i] = 0;
            cin >> val[i];
        }

        REP(i, 0, n - 1)
        {
            cin >> a >> b, arr[a].push_back(b), arr[b].push_back(a);
        }

        init();

        REP(i, 1, q + 1)
        {
            cin >> a >> b >> c;

            if (intime[a] > intime[b])
            {
                swap(a, b);
            }

            Q[i].ind = i, Q[i].c = c, Q[i].r = intime[b];

            lca = LCA(a, b);

            if (lca == a)
            {
                Q[i].l = intime[a];
                Q[i].lca = -1;
            }
            else
            {
                Q[i].l = outime[a];
                Q[i].lca = lca;
            }
        }

        sort(Q + 1, Q + q + 1, cmp);

        ML = 1, MR = 0;
        REP(i, 1, q + 1)
        {
            L = Q[i].l;
            R = Q[i].r;
            lca = Q[i].lca;
            c = Q[i].c;

            while (MR < R)
                MR++, add(MR);

            while (ML > L)
                ML--, add(ML);

            while (MR > R)
                remove(MR), MR--;

            while (ML < L)
                remove(ML), ML++;

            if (valfre[c] > 0)
            {
                ans[Q[i].ind] = 1;
            }

            if (lca != -1 && (val[lca] == c))
            {
                ans[Q[i].ind] = 1;
            }
        }

        REP(i, 1, q + 1)
        {
            if (ans[i] == 1)
            {
                cout << "Find" << endl;
                ans[i] = 0;
            }
            else
            {
                cout << "NotFind" << endl;
            }
        }
    }

    return 0;
}