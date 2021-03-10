#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<ll, ll>
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

vector<pii> arr[maxN];
ll dist[maxN];
ll paths[maxN];
ll minNode[maxN];
ll maxNode[maxN];

void bfs(int n)
{
    REP(i, 2, n + 1)
    dist[i] = INF;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    paths[1] = 1;

    while (!q.empty())
    {
        int node = q.top().second;
        ll nodeDis = q.top().first;
        q.pop();

        for (pii child : arr[node])
        {
            if (dist[child.first] > nodeDis + child.second)
            {
                dist[child.first] = nodeDis + child.second;
                paths[child.first] = paths[node];
                minNode[child.first] = minNode[node] + 1;
                maxNode[child.first] = maxNode[node] + 1;
                q.push({dist[child.first], child.first});
            }
            else if (dist[child.first] == nodeDis + child.second)
            {
                paths[child.first] = (paths[child.first] + paths[node]) % mod;
                minNode[child.first] = min(minNode[child.first], minNode[node] + 1);
                maxNode[child.first] = max(maxNode[child.first], maxNode[node] + 1);
            }
        }
    }
}

void solve()
{
    ll n, m, a, b, c;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }

    bfs(n);

    cout << dist[n] << " " << paths[n] << " " << minNode[n] << " " << maxNode[n];
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