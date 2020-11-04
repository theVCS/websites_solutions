#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001

ll res = 0;
vector<int> arr[maxN];
bool vis[maxN];
map<pair<int, int>, ll> dogs;
ll subSize[maxN];

ll dfs(int node, int par)
{
    ll cnt = 0;
    ll dogCount = dogs[{node, par}];
    vis[node] = true;
    subSize[node] = 0;
    // res = max(res, dogs[{node, par}]);

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            cnt = max(dfs(child, node), cnt);
        }
    }

    subSize[par] = cnt + dogCount;
    return subSize[par];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, a, b;
    ll dc;

    cin >> t;

    while (t--)
    {
        cin >> n;

        REP(i, 1, n + 1)
        {
            vis[i] = false;
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);

            cin >> dc;

            dogs[{a, b}] = dc;
            dogs[{b, a}] = dc;
            dogs[{a, 0}] = 0;
            dogs[{b, 0}] = 0;
        }

        dc = dfs(1, 0);

        for (int i = 1; i <= n; i++)
        {
            cout << max(subSize[i], dc - subSize[i]) << " ";
        }

        cout << endl;
    }

    return 0;
}