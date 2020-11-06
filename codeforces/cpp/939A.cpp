#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN], trans[maxN], order;
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }

    order.push_back(node);
}

int dfs1(int node)
{
    vis[node] = true;
    int cnt = 1;

    for (int child : trans[node])
    {
        if (!vis[child])
        {
            cnt += dfs1(child);
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    bool flag = true;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> d;

        arr[i].push_back(d);
        trans[d].push_back(i);
        vis[i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    REP(i, 1, n + 1)
    {
        vis[i] = false;
    }

    for (int i = order.size() - 1; i > -1; i--)
    {
        if (!vis[order[i]])
        {
            if (dfs1(order[i]) == 3)
            {
                cout << "YES";
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "NO";
    }

    return 0;
}