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

vector<int> arr[maxN], trans[maxN], order;
bool vis[maxN];
bool vis1[maxN];

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    order.push_back(node);
}

int dfs1(int node, int c)
{
    vis1[node] = true;

    for (int child : trans[node])
    {
        if (!vis1[child])
        {
            return dfs1(child, c);
        }
        else
        {
            if (c == child)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;

        arr[a].push_back(b);
        trans[b].push_back(a);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (!vis[i])
    //     {
    //         dfs(i);
    //     }
    // }

    for (int i = 1; i < n + 1; i++)
    {
        cout << dfs1(i, i) << " ";

        REP(i, 1, n + 1)
        vis1[i] = false;
    }

    return 0;
}