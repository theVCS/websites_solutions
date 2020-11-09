#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
vector<int> arr[maxN];
bool vis[maxN];
int n;

bool bus(int node)
{
    int cnt = 0;
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            cnt++;
            if (bus(child) == false)
            {
                return false;
            }
        }
    }

    if (cnt == 2 || cnt == 1 || cnt == 0)
    {
        return true;
    }

    return false;
}

bool ring(int node, int par, bool &val)
{
    int cnt = 0;
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            cnt++;

            if (ring(child, node, val) == false)
            {
                return false;
            }
        }
        else
        {
            if (child != par)
            {
                val = true;
            }
        }
    }

    if ((cnt == 2 || cnt == 1 || cnt == 0) && val)
    {
        return true;
    }

    return false;
}

bool star(int node)
{
    int cnt = 0;
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            cnt++;
            if (star(child) == false)
            {
                return false;
            }
        }
    }

    if (cnt == 1 || cnt >= (n - 2) || cnt == 0)
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

    int m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // bool val = false;
    if (star(1))
    {
        cout << "bus topology";
    }

    return 0;
}