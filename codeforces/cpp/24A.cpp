#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, res, tot_w;
vector<pair<int, int>> u_road[maxN];
vector<int> b_road[maxN];
bool vis[maxN];

bool isAbsent(int node, int child)
{
    for (pair<int, int> e : u_road[node])
    {
        if (e.first == child)
        {
            return false;
        }
    }
    return true;
}

void changeRes(int node, int child)
{
    for (pair<int, int> e : u_road[node])
    {
        if (e.first == child)
        {
            res += e.second;
        }
    }
}

void dfs(int node)
{
    vis[node] = true;

    for (int child : b_road[node])
    {
        if (!vis[child])
        {
            if (isAbsent(node, child))
            {
                changeRes(child, node);
            }

            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, w;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b >> w;
        u_road[a].push_back({b, w});

        b_road[a].push_back(b);
        b_road[b].push_back(a);

        tot_w += w;
    }

    cin >> a >> b >> w;
    u_road[a].push_back({b, w});
    b_road[a].push_back(b);
    tot_w += w;

    // call to be made using b
    dfs(b);

    cout << min(res, tot_w - res);

    return 0;
}