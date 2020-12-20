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

int n, m;
vector<int> arr[maxN], g1, g2;
bool vis[maxN];
int col[maxN];

bool dfs(int node = 1, int c = 1)
{
    vis[node] = true;
    col[node] = c;

    if (c == 0)
    {
        g1.push_back(node);
    }
    else
    {
        g2.push_back(node);
    }

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            if (dfs(child, c ^ 1) == false)
            {
                return false;
            }
        }
        else
        {
            if (col[child] == col[node])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    bool isPos = true;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    int i = 1;

    while (i <= n && isPos)
    {
        if (!vis[i])
        {
            isPos = dfs(i);
        }
        i++;
    }

    if (isPos)
    {
        cout << g1.size() << endl;
        for (int child : g1)
            cout << child << " ";
        cout << endl;

        cout << g2.size() << endl;
        for (int child : g2)
            cout << child << " ";
        cout << endl;
    }
    else
    {
        cout << -1;
    }

    return 0;
}