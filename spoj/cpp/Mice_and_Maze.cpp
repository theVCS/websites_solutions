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

void dikstra(int node)
{
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,node});
    dist[node] = 0;

    while (!q.empty())
    {
        int node = q.top().second;
        int d = q.top().first;
        q.pop();

        for(pii child: arr[node])
        {
            if(dist[child.first] > d + child.second)
            {
                dist[child.first] = d + child.second;
                q.push({dist[child.first],child.first});
            }
        }
    }
    
}

void solve()
{
    int n, e, t, m, a, b, c;

    scanf("%d %d %d %d", &n, &e, &t, &m);

    REP(i, 0, m)
    {
        scanf("%d %d %d", &a, &b, &c);
        arr[b].push_back({a, c});
    }

    memset(dist, 1000001, sizeof(dist));

    dikstra(e);

    int res = 0;

    REP(i, 1, n + 1)
    if (dist[i] <= t)
        res++;

    printf("%d", res);
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

    // scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}