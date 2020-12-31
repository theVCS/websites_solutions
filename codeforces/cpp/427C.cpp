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

ll cost[maxN], mincost, ways;
vector<int> arr[maxN], trans[maxN], order, SCC;
bool vis[maxN], vis1[maxN];

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node)
{
    vis1[node] = true;
    SCC.push_back(node);

    for (int child : trans[node])
    {
        if (!vis1[child])
        {
            dfs1(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> cost[i];
    }

    cin >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        trans[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    mincost = 0;
    ways = 1;
    ll same;

    ll dum;

    REP(i, 1, n + 1)
    {
        if (!vis1[order[n - i]])
        {
            SCC.clear();
            dum = LONG_MAX;
            dfs1(order[n - i]);

            same = 0;

            for (int e : SCC)
            {
                dum = min(dum, cost[e]);
            }

            for (int e : SCC)
            {
                if (cost[e] == dum)
                {
                    same++;
                }
            }

            ways = (ways * same) % mod;

            mincost += dum;
        }
    }

    cout << mincost << " " << ways;

    return 0;
}