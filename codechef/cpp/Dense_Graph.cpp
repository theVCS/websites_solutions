#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<int, vector<int>> arr;
map<int, bool> vis;
map<int, int> dis;

void bfs(int node, int node2)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (node == node2)
            break;

        for (int child : arr[node])
        {
            if (vis[child])
                continue;

            vis[child] = true;
            dis[child] = 1 + dis[node];
            q.push(child);
        }
    }
}

void solve()
{
    int n, m, x, y, a, b, c, d;

    scanf("%d %d %d %d", &n, &m, &x, &y);

    vis.clear();
    arr.clear();
    dis.clear();

    REP(i, 0, m)
    {
        scanf("%d %d", &a, &b);
        scanf("%d %d", &c, &d);

        for (int i = a; i <= b; i++)
        {
            for (int j = c; j <= d; j++)
            {
                arr[i].push_back(j);
            }
        }
    }

    bfs(x, y);

    if (dis[y] || x == y)
        printf("%d\n", dis[y]);
    else
        printf("-1\n");
}

int main(int argc, char const *argv[])
{
    int t = 1;

    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    return 0;
}