#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int k;
vector<pair<int, int>> arr[maxN];
bool vis[maxN];
ll powSet[maxN], res;

ll binexp(ll a, int power)
{
    ll res = 1;
    a %= mod;

    while (power)
    {
        if (power % 2)
        {
            res = (res * a) % mod;
            power--;
        }
        a = (a * a * 1LL) % mod;
        power /= 2;
    }
    return res;
}

void dfs(int node, int dep = 1)
{
    vis[node] = true;

    for (pair<int, int> e : arr[node])
    {
        if (!vis[e.first])
        {
            if (e.second == 1)
            {
                res = (res + powSet[dep]) % mod;
                dep = 0;
            }
            
            dfs(e.first, dep + 1);
        }
    }

    // res = (res + powSet[dep + 1]) % mod;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, c;

    cin >> n >> k;

    REP(i, 1, n + 1)
    {
        powSet[i] = binexp(i * 1LL, k);
    }

    REP(i, 1, n)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    dfs(1);

    // cout << res;
    // cout << powSet[1];
    cout << (powSet[n] - res + mod) % mod;
    // cout << powSet[n];

    return 0;
}