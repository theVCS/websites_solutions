#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, dp[maxN][19];
vector<int> arr[maxN];
int level[maxN];

void dfs(int node, int par = -1, int lev = 0)
{
    level[node] = lev;
    dp[node][0] = par;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, lev + 1);
        }
    }
}

void init()
{
    dfs(1);

    for (int j = 1; j < 19; j++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            if (dp[i][j - 1] == -1)
            {
                dp[i][j] = -1;
            }
            else
            {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
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
        a = dp[a][i];
        d -= 1 << i;
    }

    if (a == b)
    {
        return a;
    }
    
    for (int i = 18; i >= 0; i--)
    {
        if (dp[a][i] != dp[b][i] && dp[a][i] != -1)
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, a, b;

    cin >> n >> q;

    REP(i, 2, n + 1)
    {
        cin >> a;
        arr[a].push_back(i), arr[i].push_back(a);
    }

    init();

    while (q--)
    {
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}