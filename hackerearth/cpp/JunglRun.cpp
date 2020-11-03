#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int m, n;
char arr[31][31];
bool vis[31][31];
int dist[31][31];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n)
    {
        return false;
    }

    if (vis[x][y] || arr[x][y] == 'T')
    {
        return false;
    }

    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    dist[x][y] = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                int currx = x + dx[i];
                int curry = y + dy[i];

                vis[currx][curry] = true;
                dist[currx][curry] = dist[x][y] + 1;
                q.push({currx, curry});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int startx, starty;
    int endx, endy;
    cin >> m;
    n = m;

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'S')
            {
                startx = i;
                starty = j;
            }

            if (arr[i][j] == 'E')
            {
                endx = i;
                endy = j;
            }
        }
    }

    bfs(startx, starty);

    cout << dist[endx][endy];

    return 0;
}