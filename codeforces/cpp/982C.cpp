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
bool vis[maxN];
int even;

int dfs(int node)
{
    int cnt = 1;
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            cnt += dfs(child);
        }
    }
    if (cnt % 2 == 0)
    {
        even++;
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    cin >> n;

    REP(i, 1, n)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    if (n % 2)
    {
        cout << -1;
        return 0;
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            int k = dfs(i);
        }
    }

    cout << even - 1;

    return 0;
}