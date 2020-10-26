#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

vector<bool> vis(1001, false);
vector<int> dis(1001);

void dfs(vector<int> arr[], int n, int ndis)
{
    vis[n] = true;

    for (int P : arr[n])
    {
        if (!vis[n])
        {
            dfs(arr, P, ndis + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b, c, mn, cc;
    cin >> n;

    vector<int> arr[n + 1];
    vector<int> girls;

    e = n - 1;

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    cin >> e;

    while (e--)
    {
        cin >> c;
        girls.push_back(c);
    }

    dfs(arr, 1, 0);

    mn = dis[girls[0]];
    cc = girls[0];
    for (int P : girls)
    {
        if (mn > dis[P])
        {
            cc = P;
        }
        if (mn == dis[P])
        {
            cc = min(cc, P);
        }
    }

    cout << cc;

    return 0;
}