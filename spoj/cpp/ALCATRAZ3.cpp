#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

char maze[maxN][maxN];
bool vis[maxN][maxN];
int m, n, sx, sy, k;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n || maze[x][y] == '*')
    {
        return false;
    }
    return true;
}

bool dfs(int x = sx, int y = sy, int timer = 0)
{
    if (vis[x][y])
    {
        if (x == sx && y == sy)
        {
            if (timer >= k)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        vis[x][y] = true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            if (dfs(x + dx[i], y + dy[i], timer + 1))
            {
                return true;
            }
        }
    }

    vis[x][y] = false;

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k >> sx >> sy;

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> maze[i][j];
        }
    }

    if (dfs())
    {
        cout << "YES"<<endl;
    }
    else
    {
        cout << "NO"<<endl;
    }

    return 0;
}

// 5 5
// 14
// 1 2
// . . . * *
// * . . . *
// * . . . .
// . * . . .
// . * . . *