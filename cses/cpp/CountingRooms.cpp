#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int m, n;
char arr[1001][1001];
bool vis[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n)
    {
        return false;
    }

    if (vis[x][y] || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cc = 0;
    cin >> m >> n;

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> arr[i][j];
        }
    }

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            if (!vis[i][j] && arr[i][j] != '#')
            {
                dfs(i, j);
                cc++;
            }
        }
    }

    cout << cc;

    return 0;
}