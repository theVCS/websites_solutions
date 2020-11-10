#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m;
bool vis[21][21];
string sh, sv;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || vis[x][y])
    {
        return false;
    }

    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;

    if (sh[x - 1] == '>')
    {
        if (isValid(x, y + 1))
        {
            dfs(x, y + 1);
        }
    }
    else
    {
        if (isValid(x, y - 1))
        {
            dfs(x, y - 1);
        }
    }

    if (sv[y - 1] == 'v')
    {
        if (isValid(x + 1, y))
        {
            dfs(x + 1, y);
        }
    }
    else
    {
        if (isValid(x - 1, y))
        {
            dfs(x - 1, y);
        }
    }
}

bool check()
{
    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (vis[i][j] == false)
            {
                return false;
            }
            vis[i][j] = false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    cin >> sh;
    cin >> sv;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dfs(i, j);

            if (!check())
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}