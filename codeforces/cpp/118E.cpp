#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
vector<pair<int, int>> res;
vector<int> arr[maxN];
bool vis[maxN], hasBridge;
int intime[maxN], low[maxN], timer;

void dfs(int node, int par)
{
    vis[node] = true;
    intime[node] = low[node] = timer++;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
            
            if (intime[node] < intime[child])
            {
                res.push_back({child, node});
            }
            
        }
        else
        {
            dfs(child, node);

            if (intime[node] < low[child])
            {
                hasBridge = true;
                return;
            }

            res.push_back({node, child});
            low[node] = min(low[child], low[node]);
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

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1, -1);

    if (hasBridge)
    {
        cout << 0;
    }
    else
    {
        for (pair<int, int> p : res)
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
// 4 3
// 1 2
// 1 3
// 1 4