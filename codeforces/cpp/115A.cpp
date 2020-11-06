#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 2001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int res;

void dfs(int node, int level = 1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, level + 1);
        }
    }

    res = max(res, level);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> d;

        if (d != -1)
        {
            arr[d].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        REP(j, 1, n + 1)
        {
            vis[j] = false;
        }
        dfs(i);
    }

    cout << res;

    return 0;
}