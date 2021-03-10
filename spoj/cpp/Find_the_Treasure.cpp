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
int dis[maxN];
int parent[maxN];

void bfs()
{
    queue<int> q;
    dis[1] = 0;
    parent[1] = 0;

    for (int child : arr[1])
    {
        if (dis[child] > dis[1] + 1)
        {
            dis[child] = dis[1] + 1;
            q.push(child);
            parent[child] = 1;
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : arr[node])
        {
            if (dis[child] > dis[node] + 1)
            {
                dis[child] = dis[node] + 1;
                q.push(child);
                parent[child] = node;
            }
        }
    }
}

void solve()
{
    int n;

    scanf("%d", &n);

    dis[n] = INF;
    parent[n] = INF;

    REP(i, 1, n)
    {
        int k, dum;
        scanf("%d", &k);

        arr[i].clear();
        dis[i] = INF;
        parent[i] = INF;

        while (k--)
        {
            scanf("%d", &dum);
            arr[i].push_back(dum);
        }

        sort(all(arr[i]));
    }

    bfs();

    if (dis[n] == INF)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", dis[n]);

    vector<int> par;
    int node = parent[n];

    while (node)
    {
        par.push_back(node);
        node = parent[node];
    }
    for (int i = par.size() - 1; i >= 0; i--)
    {
        printf("%d ", par[i]);
    }
    printf("\n\n");
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
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}