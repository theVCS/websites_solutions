#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int col[maxN];
vector<ll> arr[maxN];
bool vis[maxN];
int cc, popCol;

void dfs(ll node, map<int, int> counter = {})
{
    vis[node] = true;
    counter[col[node]]++;
    popCol = max(popCol, counter[col[node]]);
    cc++;

    for (ll child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, counter);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, a, b, k, res = 0;

    cin >> n >> m >> k;

    REP(i, 1, n + 1)
    {
        cin >> col[i];
    }

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cc = 0;
            popCol = 0;

            dfs(i);

            res += cc - popCol;
        }
    }

    cout << res;

    return 0;
}