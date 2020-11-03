#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int arr[9][9];
bool vis[9][9];
int dist[9][9];
int targetX, targetY;

int getx(char a)
{
    return a - 'a' + 1;
}

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8)
    {
        return false;
    }
    if (vis[x][y])
    {
        return false;
    }
    return true;
}

int bfs(int x, int y)
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

        for (int i = 0; i < 8; i++)
        {
            int currX = x + dx[i];
            int currY = y + dy[i];

            if (isValid(currX, currY))
            {
                vis[currX][currY] = true;
                dist[currX][currY] = dist[x][y] + 1;
                q.push({currX, currY});

                if (currX == targetX && currY == targetY)
                {
                    return dist[currX][currY];
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, x, y;
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

        cin >> c >> y;
        x = getx(c);

        cin >> c >> targetY;
        targetX = getx(c);

        cout << bfs(x, y) << endl;
    }

    return 0;
}