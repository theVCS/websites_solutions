#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int m, n, res = 0, dist[51][51];
char arr[51][51];
bool vis[51][51];

bool isValid(int x, int y, char c)
{
    if (x < 1 || y < 1 || x > m || y > n || vis[x][y] || c != arr[x][y] - 1)
    {
        return false;
    }
    return true;
}

void dfs(int x, int y, int len = 1)
{
    vis[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        if (isValid(x + dx[i], y + dy[i], arr[x][y]))
        {
            dfs(x + dx[i], y + dy[i], len + 1);
        }
    }

    res = max(res, len);
}

void bfs(int x, int y)
{
    res = 1;
    vis[x][y] = true;
    dist[x][y] = 1;
    queue<pair<int, int>> q;
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

            if (isValid(currX, currY, arr[x][y]))
            {
                dist[currX][currY] = 1 + dist[x][y];
                res = max(dist[currX][currY], res);
                q.push({currX, currY});
                vis[currX][currY] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int casecnt = 1;

    while (true)
    {
        cin >> m >> n;

        if (m == 0 && n == 0)
        {
            break;
        }

        memset(vis, false, 51 * 51);
        queue<pair<int, int>> q;

        REP(i, 1, m + 1)
        {
            REP(j, 1, n + 1)
            {
                cin >> arr[i][j];

                if (arr[i][j] == 'A')
                {
                    q.push({i, j});
                }
            }
        }

        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            // dfs(q.front().first, q.front().second);
            bfs(q.front().first, q.front().second);
            q.pop();
        }

        cout<<"distance matrix"<<endl;

        REP(i, 1, m + 1)
        {
            REP(j, 1, n + 1)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }

        cout << "Case " << casecnt << ": " << res << endl;
        res = 0;
        casecnt++;
    }

    return 0;
}