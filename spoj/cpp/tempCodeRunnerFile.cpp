#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[10001];
vector<bool> vis(10001, false);

void dfs(int n)
{
    vis[n] = true;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            dfs(P);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    
    if (cnt == 1 && m == n - 1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    

    return 0;
}