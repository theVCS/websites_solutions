#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void dfs(vector<int> arr[], vector<bool> &vis, vector<int> &dis, int n, int ndis)
{
    vis[n] = true;
    dis[n] = ndis;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            dfs(arr, vis, dis, P, ndis + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b;

    cin >> n >> e;
    vector<int> arr[n + 1];
    vector<bool> vis(false, n + 1);
    vector<int> dis(n + 1);

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(arr, vis, dis, 2, 0);

    for(int P: dis)
    {
        cout<<P<<" ";
    }

    return 0;
}