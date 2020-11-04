#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 51
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool ap[10], vis[maxN][maxN];
int arr[maxN][maxN], n, sx, sy, ex, ey, res;

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || vis[x][y])
    {
        return false;
    }
    return true;
}

void dfs(int x, int y, bool ap[], int apolo = 0)
{
    vis[x][y] = true;
    bool nap[10], flag = true;

    REP(i, 0, 10)
    nap[i] = ap[i];

    if (!nap[arr[x][y]])
    {
        apolo++;
        nap[arr[x][y]] = true;
    }

    if (x == ex && y == ey)
    {
        res = min(res, apolo);

        if (apolo >= res)
        {
            flag = false;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]) && (x != ex || y != ey) && flag)
        {
            dfs(x + dx[i], y + dy[i], nap, apolo);
        }
    }

    vis[x][y] = false;
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
        cin >> n;

        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                cin >> arr[i][j];
            }
        }

        cin >> sx >> sy >> ex >> ey;
        res = INT_MAX;

        dfs(sx, sy, ap);

        cout << res << endl;
    }

    return 0;
}