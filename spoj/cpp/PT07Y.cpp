#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[10001];
vector<bool> vis(10001);
vector<int> dis(10001);

void dfs(int n, int ndis)
{
    vis[n] = true;
    dis[n] = ndis;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            dfs(P, 1 + ndis);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, cnt = 0, piv, maxD = 0;

    cin >> n;
    m = n - 1;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxD)
        {
            piv = i;
            maxD = dis[i];
        }
    }

    dis.clear();

    for (int i = 1; i < 10001; i++)
    {
        vis[i] = false;
    }
    
    maxD = 0;
    dfs(piv, 0);

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxD)
        {
            maxD = dis[i];
        }
    }

    cout << maxD;

    return 0;
}