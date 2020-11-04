#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int m, n;
char arr[maxN][maxN];
bool vis[maxN][maxN];

bool isPerimeter(int x, int y)
{
    if (x == 1 || y == 1 || x == m || y == n)
    {
        return true;
    }
    return false;
}

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n || vis[x][y] || arr[x][y] == '#')
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

    int t;

    cin >> t;

    while (t--)
    {
        queue<pair<int, int>> q;
        cin >> m >> n;

        REP(i, 1, m + 1)
        {
            REP(j, 1, n + 1)
            {
                cin >> arr[i][j];
                vis[i][j] = false;

                if (isPerimeter(i, j) && arr[i][j] == '.')
                {
                    q.push({i, j});
                }
            }
        }

        if (q.size() != 2)
        {
            cout << "invalid" << endl;
        }

        else
        {
            dfs(q.front().first, q.front().second);
            q.pop();

            if (vis[q.front().first][q.front().second])
            {
                cout << "valid" << endl;
            }
            else
            {
                cout << "invalid" << endl;
            }
        }
    }

    return 0;
}