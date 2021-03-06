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
ll cs;

ll binexp(ll n, int pow)
{
    ll res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * n) % mod;
        }
        n = (n * n) % mod;
        pow /= 2;
    }
    return res;
}

void dfs(int node)
{
    vis[node] = true;
    cs++;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, a, b, c;
    
    cin >> n >> k;

    ll res = binexp(n * 1LL, k);

    REP(i, 0, n - 1)
    {
        cin >> a >> b >> c;

        if (c == 0)
        {
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cs = 0;
            dfs(i);
            res = (res - binexp(cs, k) + mod) % mod;
        }
    }

    cout << res;

    return 0;
}