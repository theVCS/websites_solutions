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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pii> arr[maxN];
int dist[maxN];
int parent[maxN];
bool vis[maxN];

void dijk(int node = 1)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, node});

    while (!q.empty())
    {
        int d = q.top().first;
        int curr = q.top().second;
        vis[curr] = true;
        q.pop();

        if(dist[curr] < d)continue;

        for (pii e : arr[curr])
        {
            if (d + e.second < dist[e.first] && vis[e.first]==false)
            {
                dist[e.first] = d + e.second;
                q.push({dist[e.first], e.first});
                parent[e.first] = curr;
            }
        }
    }
}

void printPath(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    else
    {
        printPath(parent[n]);
        cout << n << " ";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, w;

    cin >> n >> m;

    REP(i, 1, n + 1)
    dist[i] = INT_MAX;

    while (m--)
    {
        cin >> a >> b >> w;
        arr[a].push_back({b, w});
        arr[b].push_back({a, w});
    }

    dijk(1);

    if (dist[n] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        printPath(n);
    }

    return 0;
}