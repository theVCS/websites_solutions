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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pii> arr[maxN];
int dist[maxN];

void bfs(int node)
{
    memset(dist, INF, sizeof(dist));

    deque<int>q;
    q.push_back(node);
    dist[node] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();

        for(pii child: arr[node])
        {
            if(child.second == 0)
            {
                if(dist[child.first] > dist[node])
                {
                    dist[child.first] = dist[node];
                    q.push_front(child.first);
                }
            }
            else
            {
                if(dist[child.first] > dist[node] + 1)
                {
                    dist[child.first] = dist[node] + 1;
                    q.push_back(child.first);
                }
            }
        }
    }
}

void solve()
{
    int n, m, a, b, c;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back({b, 0}), arr[b].push_back({a, 1});
    }

    bfs(1);

    if(dist[n] == INF)cout << -1;
    else cout << dist[n];
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