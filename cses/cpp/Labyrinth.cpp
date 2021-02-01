#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char arr[maxN][maxN];
bool vis[maxN][maxN];
int dist[maxN][maxN];

int n, m;

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

bool isValid2(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

void bfs(int x, int y, string s = "")
{
    vis[x][y] = true;
    dist[x][y] = 0;
    queue<pii> q;
    q.push({x, y});

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                vis[x + dx[i]][y + dy[i]] = true;
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;

                q.push({x + dx[i], y + dy[i]});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sx, sy, ex, ey;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'A')
            {
                sx = i, sy = j;
            }

            if (arr[i][j] == 'B')
            {
                ex = i, ey = j;
            }
        }
    }

    bfs(sx, sy);

    if (vis[ex][ey])
    {
        cout << "YES" << endl;
        cout << dist[ex][ey] << endl;

        string s;

        while (dist[ex][ey])
        {
            // cout << ex << " " << ey << endl;
            for (int i = 0; i < 4; i++)
            {
                if (isValid2(ex + dx[i], ey + dy[i]))
                {
                    if (dist[ex][ey] > dist[ex + dx[i]][ey + dy[i]])
                    {
                        if (i == 0)
                        {
                            s.push_back('D');
                        }
                        else if (i == 1)
                        {
                            s.push_back('R');
                        }
                        else if (i == 2)
                        {
                            s.push_back('U');
                        }
                        else
                        {
                            s.push_back('L');
                        }

                        ex = ex + dx[i], ey = ey + dy[i];
                    }
                }
            }
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    else
    {
        cout << "NO";
    }

    return 0;
}