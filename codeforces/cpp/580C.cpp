#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int cat[maxN], res, n, m, a, b;

void dfs(int node, int par, int cats)
{
    bool flag = true;
    vis[node] = true;

    if (cat[node] && cat[par])
    {
        cats++;
    }
    else
    {
        cats = cat[node];
    }

    if (cats > m)
    {
        return;
    }

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            flag = false;
            dfs(child, node, cats);
        }
    }

    if (flag)
    {
        res++;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1, 0, cat[1]);

    cout << res;

    return 0;
}