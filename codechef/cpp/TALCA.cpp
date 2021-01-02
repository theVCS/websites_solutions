#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, parent[maxN][17], level[maxN];
vector<int> arr[maxN];
bool vis[maxN];

void dfs(int node, int par = 0, int lev = 0)
{
    vis[node] = true;
    parent[node][0] = par;
    level[node] = lev;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, node, lev + 1);
        }
    }
}

void init()
{
    dfs(1);

    for (int j = 1; j < 17; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != 0)
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

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
    {
        return a;
    }

    for (int i = 16; i >= 0; i--)
    {
        if (parent[a][i] != 0 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int dist(int a, int b, int r, int lca)
{
    int _a = level[a] + level[lca] - 2 * level[LCA(lca, a)];
    int _b = level[b] + level[lca] - 2 * level[LCA(lca, b)];
    int _r = level[r] + level[lca] - 2 * level[LCA(lca, r)];

    return _a + _b + _r;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, q, r;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    init();

    cin >> q;

    while (q--)
    {
        cin >> r >> a >> b;

        vector<pair<int, int>> vec;
        int l, d;

        l = LCA(r, a);
        d = dist(a, b, r, l);
        vec.push_back({d, l});

        l = LCA(r, b);
        d = dist(a, b, r, l);
        vec.push_back({d, l});

        l = LCA(b, a);
        d = dist(a, b, r, l);
        vec.push_back({d, l});

        sort(vec.begin(), vec.end());

        // for (pair<int, int> e : vec)
        // {
        //     cout << e.first << " <----> " << e.second << endl;
        // }

        cout << vec[0].second << endl;
    }

    return 0;
}