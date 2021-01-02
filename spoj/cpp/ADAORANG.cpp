#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 450001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, shades[maxN];
vector<int> arr[maxN];
bool vis[maxN];
int level[maxN], parent[maxN];

void dfs(int node, int par = -1, int lev = 0)
{
    vis[node] = true;
    level[node] = lev;
    parent[node] = par;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, node, lev + 1);
        }
    }
}

int LCA(int a, int b)
{
    set<int> s;

    if (level[a] < level[b])
    {
        swap(a, b);
    }

    int d = level[a] - level[b];

    while (d--)
    {
        s.insert(shades[a]);
        a = parent[a];
    }

    while (a != b)
    {
        s.insert(shades[a]);
        s.insert(shades[b]);
        a = parent[a];
        b = parent[b];
    }

    s.insert(shades[a]);

    return s.size();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, q, r, a, b;

    cin >> t;

    while (t--)
    {
        cin >> n >> q >> r;

        REP(i, 0, n)
        cin >> shades[i], vis[i] = false, arr[i].clear();

        REP(i, 0, n - 1)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        dfs(r);

        while (q--)
        {
            cin >> a >> b;
            cout << LCA(a, b) << endl;
        }
    }

    return 0;
}