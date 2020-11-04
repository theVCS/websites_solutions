#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int sx, sy, ex, ey, dist[9][9];
bool vis[9][9];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8 || vis[x][y])
    {
        return false;
    }
    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    vis[x][y] = true;
    dist[x][y] = 0;
    q.push({x, y});

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int currX = x + dx[i];
            int currY = y + dy[i];

            if (isValid(currX, currY))
            {
                vis[currX][currY] = true;
                dist[currX][currY] = 1 + dist[x][y];
                q.push({currX, currY});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    char c;

    cin >> t;

    while (t--)
    {
        REP(i, 1, 9)
        {
            REP(j, 1, 9)
            {
                vis[i][j] = false;
            }
        }

        cin >> c;
        sx = c - 'a' + 1;
        cin >> sy;

        cin >> c;
        ex = c - 'a' + 1;
        cin >> ey;

        bfs(sx, sy);
        cout << dist[ex][ey] << endl;
    }

    return 0;
}