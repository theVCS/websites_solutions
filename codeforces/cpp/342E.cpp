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
#define INF 1000000
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

set<int> arr[maxN];
int subSize[maxN];
int parent[maxN];
int dp[maxN][21];
int level[maxN];
int res[maxN];

// decomposition part
int dfs0(int node, int par)
{
    subSize[node] = 1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        subSize[node] += dfs0(child, node);
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
    int n = dfs0(node, par);
    int centroid = cenCal(node, par, n);

    parent[centroid] = par;

    for (int child : arr[centroid])
    {
        arr[child].erase(centroid), decompose(child, centroid);
    }
}

// initialization part
void dfs(int node, int par, int l)
{
    level[node] = l;
    dp[node][0] = par;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node, l + 1);
    }
}

void init(int n)
{
    dfs(1, -1, 0);

    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (dp[i][j - 1] == -1)
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

    for (int i = 20; i >= 0; i--)
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

void update(int node)
{
    int curr = node;

    while (curr != -1)
    {
        res[curr] = min(res[curr], dist(curr, node));
        curr = parent[curr];
    }
}

int query(int node)
{
    int curr = node;
    int ans = INT_MAX;

    while (curr != -1)
    {
        ans = min(ans * 1LL, (res[curr] * 1LL + dist(curr, node)) * 1LL);
        curr = parent[curr];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].insert(b), arr[b].insert(a);
    }

    init(n);
    decompose(1, -1);
    REP(i, 1, n + 1)
    res[i] = INT_MAX;
    update(1);

    while (m--)
    {
        cin >> a >> b;

        if (a == 1)
            update(b);
        else
            cout << query(b) << endl;
    }

    return 0;
}