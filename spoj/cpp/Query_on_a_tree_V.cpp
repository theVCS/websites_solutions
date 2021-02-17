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

set<int> arr[maxN];
int parent[maxN];
int subSize[maxN];

// decomposition part

int dfs(int node, int par)
{
    subSize[node] = 1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        subSize[node] += dfs(child, node);
    }

    return subSize[node];
}

int cenCal(int node, int par, int n)
{
    for (int child : arr[node])
    {
        if (child == par)
            continue;

        if (subSize[child] > n / 2)
            return cenCal(child, node, n);
    }

    return node;
}

void decompose(int node, int par)
{
    int n = dfs(node, -1);
    int centroid = cenCal(node, -1, n);

    parent[centroid] = par;

    for (int child : arr[centroid])
    {
        arr[child].erase(centroid), decompose(child, centroid);
    }
}

// initialization part
int level[maxN], dp[maxN][17];

void dfs1(int node, int par = -1, int l = 0)
{
    level[node] = l;
    dp[node][0] = par;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs1(child, node, l + 1);
    }
}

void init(int n)
{
    dfs1(1);

    for (int j = 1; j < 17; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[i][j] == -1)
                dp[i][j] = -1;
            else
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
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
        a = dp[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 16; i >= 0; i--)
    {
        if (dp[a][i] != -1 && dp[a][i] != dp[b][i])
        {
            a = dp[a][i], b = dp[b][i];
        }
    }

    return dp[a][0];
}

int dist(int a, int b)
{
    return level[a] + level[b] - 2 * level[LCA(a, b)];
}

int col[maxN];
set<pii> res[maxN];

// 0 -> black
// 1 -> white

void update(int node)
{
    int curr = node, d;

    while (curr != -1)
    {
        d = dist(curr, node);

        if (col[node] == 0)
            res[curr].insert({d, node});
        else
            res[curr].erase({d, node});

        curr = parent[curr];
    }

    col[node] ^= 1;
}

int query(int node)
{
    int curr = node;
    int ans = 100000;

    while (curr != -1)
    {
        for (pii e : res[curr])
        {
            ans = min(ans, e.first + dist(curr, node));
            break;
        }

        curr = parent[curr];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n, m, a, b;

    scanf("%d", &n);

    REP(i, 0, n - 1)
    {
        scanf("%d %d", &a, &b);
        arr[a].insert(b), arr[b].insert(a);
    }

    init(n);
    decompose(1, -1);

    scanf("%d", &m);

    while (m--)
    {
        scanf("%d %d", &a, &b);

        if (a == 0)
        {
            update(b);
        }
        else
        {
            int res = query(b);
            printf("%d\n", res == 100000 ? -1 : res);
        }
    }

    return 0;
}