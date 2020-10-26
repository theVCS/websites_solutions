#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define maxN 100001
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[maxN];
vector<bool> vis(maxN, false);
ll cnt;

void dfs(int n)
{
    vis[n] = true;
    cnt++;

    for (int c : arr[n])
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, m, a, b, paths, leader;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i < maxN; i++)
        {
            arr[i].clear();
            vis[i] = false;
        }

        while (m--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        leader = 1;
        paths = 0;

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cnt = 0;
                dfs(i);
                leader = (leader * cnt) % mod;
                paths++;
            }
        }
        cout << paths << " " << leader << endl;
    }

    return 0;
}