#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
vector<int> arr[maxN];
ll gold[maxN];
int n, m;
bool vis[maxN];
ll rgold;

int dfs(int node)
{
    vis[node] = true;
    rgold = min(rgold, gold[node - 1]);

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    ll res = 0;

    cin >> n >> m;

    REP(i, 0, n)
    {
        cin >> gold[i];
    }

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            rgold = __LONG_LONG_MAX__;
            dfs(i);
            res += rgold;
        }
    }

    cout << res;

    return 0;
}