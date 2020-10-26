#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

vector<int> arr[10001];
vector<bool> vis(10001, false);
vector<int> dis(10001);

void dfs(int n, int ndis)
{
    vis[n] = true;
    dis[n] = ndis;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            dfs(P, ndis + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    cin >> n;

    n--;
    while (n--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs()

    return 0;
}