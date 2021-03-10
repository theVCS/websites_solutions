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

vector<int> arr[maxN];
int dist[maxN];
int parent[maxN];

void bfs(int n)
{
    REP(i, 1, n)
    dist[i] = -100001;

    priority_queue<pii, vector<pii>> q;
    q.push({0, n});

    while (!q.empty())
    {
        int node = q.top().second;
        int nodeDis = q.top().first;
        q.pop();

        for (int child : arr[node])
        {
            if (dist[child] < nodeDis + 1)
            {
                dist[child] = nodeDis + 1;
                parent[child] = node;
                q.push({dist[child], child});
            }
        }
    }
}

void solve()
{
    int n, m, a, b;

    // cin >> n >> m;
    scanf("%d %d", &n, &m);

    REP(i, 0, m)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        arr[b].push_back(a);
    }

    bfs(n);

    if (parent[1] == 0)
    {
        // cout << "IMPOSSIBLE";
        printf("IMPOSSIBLE");
        return;
    }

    int node = 1;

    // cout << dist[1] + 1 << endl;
    printf("%d\n", dist[1] + 1);

    while (node)
    {
        // cout << node << " ";
        printf("%d ", node);
        node = parent[node];
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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