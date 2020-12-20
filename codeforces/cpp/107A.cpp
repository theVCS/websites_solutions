#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, p;
vector<pair<int, int>> arr[maxN]; // {index, weight}
vector<int> order;
bool vis[maxN];
bool vis1[maxN];
vector<pair<pair<int, int>, int>> res;

void dfs(int node)
{
    vis[node] = true;

    for (pair<int, int> child : arr[node])
    {
        if (!vis[child.first])
        {
            dfs(child.first);
        }
    }
    order.push_back(node);
}

void dfs1(int node, int tank, int dia = INT_MAX, bool flag = false)
{
    vis1[node] = true;

    if (arr[node].size() == 0 && flag)
    {
        res.push_back({{tank, node}, dia});
    }

    for (pair<int, int> e : arr[node])
    {
        if (!vis1[e.first])
        {
            dfs1(e.first, tank, min(dia, e.second), true);
        }
    }
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.first < b.first.first)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, w;

    cin >> n >> p;

    if (p)
    {
        REP(i, 0, p)
        {
            cin >> a >> b >> w;
            arr[a].push_back({b, w});
        }

        REP(i, 1, n + 1)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }

        for (int i = order.size() - 1; i > 0; i--)
        {
            if (!vis1[order[i]])
            {
                dfs1(order[i], order[i]);
            }
        }
    }

    int m = res.size();

    cout << m << endl;

    if (m)
    {
        sort(res.begin(), res.end(), comp);

        for (pair<pair<int, int>, int> e : res)
        {
            cout << e.first.first << " " << e.first.second << " " << e.second << endl;
        }
    }

    return 0;
}