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

int n;
vector<int> arr[maxN], c1, c2;
bool vis[maxN];

void dfs(int node, int c = 0)
{
    vis[node] = true;

    if (c == 0)
    {
        c1.push_back(node);
    }
    else
    {
        c2.push_back(node);
    }

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, c ^ 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    ll res;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    res = c1.size() * c2.size();

    for (int child : c1)
        res -= arr[child].size();

    cout << res;

    return 0;
}