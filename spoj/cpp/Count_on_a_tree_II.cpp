#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN1 100011
#define maxN2 100011
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int blk = 700;

// initialization
vector<int> arr[maxN1];
int col[maxN1], level[maxN1], parent[maxN1][19];

// flattening tree
int FT[2 * maxN1], intime[maxN1], outime[maxN1], timer;

// frequency
map<int, int> fre;
int compressed_value, colFre[maxN1], nodeFre[maxN1];

// answer
int ans[maxN2], res;

void dfs(int node = 1, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    FT[timer] = node;
    parent[node][0] = par;
    level[node] = l;

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

    for (int j = 1; j < 19; j++)
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

    for (int i = 18; i >= 0; i--)
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
} Q[maxN2];

bool cmp(query a, query b)
{
    int x = a.l / blk, y = b.l / blk;
    return (x < y) || (x == y && a.r < b.r);
}

void add(int index)
{
    int node = FT[index];
    int c = col[node];

    nodeFre[node]++;

    if (nodeFre[node] == 1)
    {
        colFre[c]++;

        if (colFre[c] == 1)
            res++;
    }
    else if (nodeFre[node] == 2)
    {
        colFre[c]--;

        if (colFre[c] == 0)
            res--;
    }
}

void remove(int index)
{
    int node = FT[index];
    int c = col[node];

    nodeFre[node]--;

    if (nodeFre[node] == 1)
    {
        colFre[c]++;

        if (colFre[c] == 1)
            res++;
    }
    else if (nodeFre[node] == 0)
    {
        colFre[c]--;

        if (colFre[c] == 0)
            res--;
    }
}

int main(int argc, char const *argv[])
{
    int n, m, a, b;

    while (scanf("%d", &n) != EOF)
    {
        scanf("%d", &m);

        timer = 0;
        fre.clear();
        compressed_value = 0;
        res = 0;
        colFre[0] = 0;

        REP(i, 1, n + 1)
        {
            scanf("%d", col + i);
            fre[col[i]];
            arr[i].clear();
            colFre[i] = 0;
        }

        // cordinate compression
        for (auto &it : fre)
        {
            it.second = compressed_value++;
        }
        for (int i = 1; i < n + 1; i++)
        {
            col[i] = fre[col[i]];
        }

        REP(i, 0, n - 1)
        scanf("%d %d", &a, &b), arr[a].push_back(b), arr[b].push_back(a);

        init(n);

        REP(i, 1, m + 1)
        {
            scanf("%d %d", &a, &b);

            if (intime[a] > intime[b])
                swap(a, b);

            int lca = LCA(a, b);

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

            Q[i].r = intime[b];
            Q[i].index = i;
        }

        sort(Q + 1, Q + 1 + m, cmp);

        for (int i = 1, L = 1, R = 0; i <= m; i++)
        {
            while (L < Q[i].l)
                remove(L++);
            while (L > Q[i].l)
                add(--L);
            while (R < Q[i].r)
                add(++R);
            while (R > Q[i].r)
                remove(R--);

            ans[Q[i].index] = res;

            int lca = Q[i].lca;

            if (lca > 0)
            {
                int c = col[lca];

                if (colFre[c] == 0)
                    ans[Q[i].index] += 1;
            }
        }

        REP(i, 1, m + 1)
        printf("%d\n", ans[i]);
    }

    return 0;
}