#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int intime[maxN], low[maxN], timer;
vector<pair<int, int>> bridge;

void dfs(int node = 1, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;

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
            low[node] = min(low[node], low[child]);

            if (intime[node] < low[child])
            {
                bridge.push_back({node, child});
            }
        }
    }
}

ll sr(int node)
{
    ll cnt = 1;
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            cnt += sr(child);
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, a, b;
    ll ways = 0, totWays, size;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    for (pair<int, int> e : bridge)
    {
        arr[e.first].erase(remove(arr[e.first].begin(), arr[e.first].end(), e.second), arr[e.first].end());
        arr[e.second].erase(remove(arr[e.second].begin(), arr[e.second].end(), e.first), arr[e.second].end());
    }

    REP(i, 0, n + 1)
    vis[i] = false;

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            size = sr(i);
            if (size > 1)
            {
                ways += size * (size - 1) / 2;
            }
        }
    }

    totWays = (n - 1) * n / 2;

    printf("%.5f", 1 - (ways * 1.0 / totWays));

    return 0;
}