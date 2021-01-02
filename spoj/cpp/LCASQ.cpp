#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, parent[maxN][13], level[maxN];
vector<int> arr[maxN];
bool vis[maxN];

void dfs(int node, int par = -1, int lev = 0)
{
    vis[node] = true;
    level[node] = lev;
    parent[node][0] = par;

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
    dfs(0);

    for (int j = 1; j < 13; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
            else
            {
                parent[i][j] = -1;
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

    for (int i = 12; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, a, b;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> m;

        while (m--)
        {
            cin >> b;
            arr[i].push_back(b);
            arr[b].push_back(i);
        }
    }

    init();

    cin >> m;

    while (m--)
    {
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}