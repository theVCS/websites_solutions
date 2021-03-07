#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
ll dx[] = {-1, 1};

map<ll, ll> vis;
vector<ll> ans, trees;
queue<pair<ll, ll>> q;

bool isValid(ll x)
{
    if (vis[x])
        return false;
    return true;
}

void solve()
{
    ll n, m, dum;

    cin >> n >> m;

    REP(i, 0, n)
    {
        cin >> dum;
        vis[dum] = true;
        trees.push_back(dum);
    }

    for (ll tree : trees)
    {
        REP(i, 0, 2)
        {
            if (isValid(tree + dx[i]))
            {
                vis[tree + dx[i]] = true;
                q.push({tree + dx[i], 1});
            }
        }
    }

    ll res = 0;

    while (ans.size() < m)
    {
        pii node = q.front();
        q.pop();
        res += node.second;
        ans.push_back(node.first);

        REP(i, 0, 2)
        {
            if (isValid(node.first + dx[i]))
            {
                q.push({node.first + dx[i], node.second + 1});
                vis[node.first + dx[i]] = true;
            }
        }
    }

    cout << res << endl;

    for (ll e : ans)
        cout << e << " ";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}