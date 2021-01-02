#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[1001];
bool vis[1001];
int dist[1001];

void dfs(int node, int dis = 0)
{
    vis[node] = true;
    dist[node] = dis;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, dis + 1);
        }
    }
}

int par(int a)
{
    for (int e : arr[a])
    {
        if (dist[e] < dist[a])
        {
            return e;
        }
    }
}

int LCA(int a, int b)
{
    if (dist[a] < dist[b])
    {
        swap(a, b);
    }
    int d = dist[a] - dist[b];

    while (d--)
    {
        a = par(a);
    }

    while (a != b)
    {
        a = par(a);
        b = par(b);
    }

    return a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, a, m, q;

    cin >> t;

    REP(k, 1, t + 1)
    {
        cin >> n;

        REP(i, 1, n + 1)
        {
            cin >> m;

            while (m--)
            {
                cin >> a;
                arr[i].push_back(a);
                arr[a].push_back(i);
            }
        }

        dfs(1);

        cin >> q;

        cout << "Case " << k << ":" << endl;

        while (q--)
        {
            cin >> a >> m;
            cout << LCA(a, m) << endl;
        }

        REP(i, 0, n + 1)
        vis[i] = false, arr[i].clear(), dist[i] = 0;
    }

    return 0;
}