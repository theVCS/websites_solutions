#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
vector<pair<int, int>> arr[maxN];
bool vis[maxN];

ll dfs(int node = 0)
{
    vis[node] = true;
    ll res = 0;

    for (pair<int, int> e : arr[node])
    {
        if (!vis[e.first])
        {
            res = max(res, e.second * 1LL + dfs(e.first));
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, w;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b >> w;

        arr[a].push_back({b, w});
        arr[b].push_back({a, w});
    }

    cout << dfs();

    return 0;
}