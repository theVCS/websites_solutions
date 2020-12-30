#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool vis[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, root = 0;
    vector<pair<int, int>> res;
    vector<int> alone;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        res.push_back({a, b});
        vis[a] = vis[b] = true;
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            root = i;
            break;
        }
        vis[i] = false;
    }

    REP(i, root + 1, n + 1)
    {
        if (!vis[i])
        {
            alone.push_back(i);
        }
        vis[i] = false;
    }

    cout << n - 1 << endl;

    for (pair<int, int> e : res)
    {
        if (!vis[e.first])
        {
            cout << root << " " << e.first << endl;
            vis[e.first] = true;
        }

        if (!vis[e.second])
        {
            cout << root << " " << e.second << endl;
            vis[e.second] = true;
        }

    }

    for (int e : alone)
    {
        if (!vis[e])
        {
            cout << root << " " << e << endl;
            vis[e] = true;
        }
        
    }

    return 0;
}