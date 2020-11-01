#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 701
vector<int> arr[maxN];
int intime[maxN], low[maxN], timer;
bool vis[maxN];
vector<pair<int, int>> res;

bool comparison(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first < p2.first)
        return true;
    if (p1.first > p2.first)
        return false;
    return p1.second <= p2.second;
}

void dfs(int node, int par = -1)
{
    intime[node] = low[node] = timer++;
    vis[node] = true;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else
        {
            dfs(child, node);

            if (low[child] > intime[node])
            {
                if (node < child)
                {
                    res.push_back({node, child});
                }
                else
                {
                    res.push_back({child, node});
                }
            }

            low[node] = min(low[node], low[child]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, e, a, b;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        timer = 0;
        res.clear();
        for (int i = 0; i < maxN; i++)
        {
            arr[i].clear();
            vis[i] = false;
        }

        cin >> n >> e;

        while (e--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        dfs(1);

        cout << "Caso #" << i << endl;

        if (res.size())
        {
            cout << res.size() << endl;
            sort(res.begin(), res.end(), comparison);

            for (pair<int, int> e : res)
            {
                cout << e.first << " " << e.second << endl;
            }
        }
        else
        {
            cout << "Sin bloqueos" << endl;
        }
    }

    return 0;
}