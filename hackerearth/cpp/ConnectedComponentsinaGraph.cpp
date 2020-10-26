#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void dfs(vector<int> arr[], vector<bool> &vis, int n)
{
    vis[n] = true;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            dfs(arr, vis, P);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b, cc = 0;
    cin >> n >> e;
    vector<int> arr[n + 1];
    vector<bool> vis(n + 1, false);

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(arr, vis, i);
            cc++;
        }
    }

    cout << cc;

    return 0;
}