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

vector<pair<int, ll>> arr[maxN];
int centre[maxN], n, m, k;
ll res = __LONG_LONG_MAX__;

void dfs(int centre[])
{
    REP(i, 0, k)
    {
        for(pair<int,ll>e: arr[centre[i]])
        {
            res = min(res, e.second);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    ll w;

    cin >> n >> m >> k;

    REP(i, 0, m)
    {
        cin >> a >> b >> w;
        arr[a].push_back({b, w});
        arr[b].push_back({a, w});
    }

    REP(i, 0, k)
    {
        cin >> centre[i];
    }

    dfs(centre);

    if (res == __LONG_LONG_MAX__)
    {
        cout << -1;
    }
    else
    {
        cout << res;
    }
    

    return 0;
}