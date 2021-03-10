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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];

void bfs(queue<pii> q)
{
    while (!q.empty())
    {
        pii node = q.front();
        q.pop();

        for (int child : arr[node.first])
        {
            if (vis[child])
                continue;

            if (node.second > 0)
            {
                vis[child] = true;
                q.push({child, node.second - 1});
            }
        }
    }
}

void solve()
{
    int n, r, m, a, b;
    queue<pii> q;

    scanf("%d %d %d", &n, &r, &m);

    REP(i, 0, r)
    {
        scanf("%d %d", &a, &b);
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 0, m)
    {
        scanf("%d %d", &a, &b);
        vis[a] = true;
        q.push({a, b});
    }

    bool flag = true;

    bfs(q);

    REP(i, 1, n + 1)
    {
        flag &= vis[i];
        vis[i] = false;
        arr[i].clear();
    }

    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
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

    // cin >> t;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}