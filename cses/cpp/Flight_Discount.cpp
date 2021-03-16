#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pil pair<int, ll>
#define pli pair<ll, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define endl "\n"
#define INF 1000000000000000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pil> arr[maxN];

struct info
{
    ll dist;
    ll maxLen;

    info()
    {
        dist = INF;
        maxLen = -INF;
    }
};
vector<info> paths[maxN];

void bfs()
{
    info e;
    queue<int> q;
    q.push(1);
    e.dist = 0, e.maxLen = 0;
    paths[1].push_back(e);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (info dat : paths[node])
        {
            ll disNode = dat.dist;
            ll mxLenNode = dat.maxLen;

            for (pil child : arr[node])
            {
                if (child.first == 1)
                    continue;
                e.dist = disNode + child.second;
                e.maxLen = max(mxLenNode, child.second);
                paths[child.first].push_back(e);
                q.push(child.first);
            }
        }
    }
}

void solve()
{
    int n, m, a, b;
    ll c;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }

    bfs();
    // cout << dist[n] - maxLen[n] + (maxLen[n] / 2);
    for (info e : paths[6])
        cout << e.dist << " " << e.maxLen << endl;
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