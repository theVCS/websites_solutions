#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN], newGraph[maxN];
vector<int> tree[maxN];
int par[maxN], depth[maxN];
bool vis[maxN];

void solve()
{
    int n, m, a, b;
    cin >> n >> m;

    REP(i, 0, n + 1)
    {
        vis[i] = false;
        arr[i].clear();
        tree[i].clear();
        newGraph[i].clear();
        depth[i] = 0;
    }

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    vector<pii> edges;

    REP(i, 1, n + 1)
    {
        edges.push_back({arr[i].size(), i});
    }

    sort(all(edges), greater<pair<int, int>>());

    if (edges[0].first != n - 1)
    {
        cout << "NO" << endl;
        return;
    }

    par[edges[0].second] = 0;
    vis[edges[0].second] = true;
    depth[edges[0].second] = 1;

    for (int i = 1; i < n; i++)
    {
        int mxdepth = -1;
        int node = edges[i].second;
        vis[node] = true;
        int ans = -1;

        for (int child : arr[node])
        {
            if (vis[child] && depth[child] > mxdepth)
            {
                ans = child;
                mxdepth = depth[child];
            }
        }

        if (ans == -1)
        {
            cout << "NO" << endl;
            return;
        }

        tree[node].push_back(ans);
        tree[ans].push_back(node);
        par[node] = ans;
        depth[node] = depth[ans] + 1;
    }

    vector<int> q;
    q.push_back(edges[0].second);
    memset(vis, false, sizeof(vis));
    vis[edges[0].second] = true;

    int M = 0;

    while (!q.empty())
    {
        int node = q.back();
        bool flag = true;

        for (int child : tree[node])
        {
            if (vis[child] == false)
            {
                vis[child] = true;
                q.push_back(child);
                flag = false;
                break;
            }
        }

        if (flag)
        {
            for (int i = 0; i < q.size() - 1; i++)
            {
                newGraph[q[i]].push_back(q.back());
                newGraph[q.back()].push_back(q[i]);
                ++M;

                if (M > m)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            q.pop_back();
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i].size() != newGraph[i].size())
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    REP(i, 1, n + 1)
    cout << par[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}