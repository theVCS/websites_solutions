#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5001
#define endl "\n"
#define INF 1000000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct edge
{
    int a, b;
    ll w;
} arr[maxN];

vector<ll> dis(2501, -1 * INF);

void bellmanFord(int m)
{
    dis[1] = 0;

    while (true)
    {
        bool flag = true;

        REP(i, 0, m)
        {
            if (dis[arr[i].a] != -1 * INF && dis[arr[i].b] < dis[arr[i].a] + arr[i].w)
            {
                dis[arr[i].b] = dis[arr[i].a] + arr[i].w;
                flag = false;
            }
        }

        if (flag)
            break;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    REP(i, 0, m)
    cin >> arr[i].a >> arr[i].b >> arr[i].w;

    bellmanFord(m);

    cout << dis[n];
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