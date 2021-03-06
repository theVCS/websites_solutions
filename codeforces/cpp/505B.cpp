#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pii> arr[maxN];
set<int> cols;
int u, v;
bool vis[maxN];

void ways(int node, int col = 0)
{
    if (node == v)
    {
        cols.insert(col);
        return;
    }

    vis[node] = true;

    for (pii child : arr[node])
    {
        if (vis[child.first])
            continue;

        if (col == 0 || col == child.second)
        {
            ways(child.first, child.second);
        }
    }

    vis[node] = false;
}

void solve()
{
    int n, m, a, b, c;
    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c}), arr[b].push_back({a, c});
    }

    int q;
    cin >> q;

    while (q--)
    {
        cols.clear();
        cin >> u >> v;
        ways(u);
        cout << cols.size() << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}