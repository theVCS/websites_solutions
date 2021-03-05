#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 3001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int parent[maxN][maxN];
map<int, map<int, map<int, int>>> mp;

struct nodeData
{
    int node, par;
} e;

void solve()
{
    int n, m, k, a, b, c;

    cin >> n >> m >> k;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 0, k)
    {
        cin >> a >> b >> c;
        mp[a][b][c] = 1;
    }

    queue<nodeData> q;
    e.node = 1, e.par = 0;
    q.push(e);
    parent[1][1] = 1;
    nodeData res;
    res.node = n, res.par = -1;

    while (!q.empty())
    {
        e = q.front();
        q.pop();

        if (e.node == n)
        {
            res = e;
            break;
        }

        for (int child : arr[e.node])
        {
            if (parent[e.node][child] || mp[e.par][e.node][child])
                continue;

            nodeData obj;
            obj.node = child, obj.par = e.node;
            q.push(obj);
            parent[e.node][child] = e.par;
        }
    }

    if (res.par == -1)
    {
        cout << -1;
        return;
    }

    vector<int> path;

    while (res.node != 1)
    {
        path.push_back(res.node);
        nodeData p;
        p.par = parent[res.par][res.node];
        p.node = res.par;
        res = p;
    }
    path.push_back(1);

    cout << path.size() - 1 << endl;

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
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