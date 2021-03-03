#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1011
#define all(x) (x).begin(), (x).end()
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m;
char arr[maxN][maxN];
bool vis[maxN][maxN];
int dis[maxN][maxN];
int surDis[maxN][maxN];
int dir[maxN][maxN];
int sx, sy, ex, ey;

// for monsters
bool isValid1(int x, int y)
{
    if (vis[x][y] || x < 1 || x > n || y < 1 || y > m || arr[x][y] == '#')
        return false;

    return true;
}

// for monsters
void bfs1(queue<pii> q)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        REP(i, 0, 4)
        {
            int X = x + dx[i], Y = y + dy[i];

            if (isValid1(X, Y))
            {
                vis[X][Y] = true;
                dis[X][Y] = min(dis[X][Y], 1 + dis[x][y]);
                q.push({X, Y});
            }
        }
    }
}

// for survivor
bool isValid(int x, int y, int steps)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == 'M' || arr[x][y] == '#' || vis[x][y] || dis[x][y] <= steps)
        return false;

    return true;
}

// for survivor
void bfs()
{
    queue<pii> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    surDis[sx][sy] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 1 || x == n || y == 1 || y == m)
        {
            ex = x, ey = y;
            return;
        }

        REP(i, 0, 4)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y, surDis[x][y] + 1))
            {
                vis[X][Y] = true;
                q.push({X, Y});
                surDis[X][Y] = 1 + surDis[x][y];
                dir[X][Y] = i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    queue<pii> cor;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'A')
                sx = i, sy = j;

            if (arr[i][j] == 'M')
                cor.push({i, j});
            else
                dis[i][j] = INT_MAX;
        }
    }

    // finding minimum steps
    if (cor.size())
        vis[cor.front().first][cor.front().second] = true;
    bfs1(cor);

    memset(vis, false, sizeof(vis));

    bfs();
    if (ex && ey)
    {
        cout << "YES" << endl;
        vector<char> path;

        while (true)
        {
            if (ex == sx && ey == sy)
                break;

            int d = dir[ex][ey];

            if (d == 0)
            {
                path.push_back('U');
            }
            else if (d == 1)
            {
                path.push_back('L');
            }
            else if (d == 2)
            {
                path.push_back('D');
            }
            else
            {
                path.push_back('R');
            }

            ex -= dx[d];
            ey -= dy[d];
        }

        cout << path.size() << endl;

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}