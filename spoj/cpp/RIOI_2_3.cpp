#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[50][50], sx, sy, ex, ey, res[50][50], n;
bool vis[50][50];

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || vis[x][y])
    {
        return false;
    }
    return true;
}

int dfs(int x, int y, map<int, bool> checker = {})
{
    if (x == ex && y == ey)
    {
        return int(!checker[arr[x][y]]);
    }

    vis[x][y] = true;
    int res = 20;
    int flag = int(!checker[arr[x][y]]), dum;

    checker[arr[x][y]] = true;


    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dum = flag;
            if (!checker[arr[x + dx[i]][y + dy[i]]])
            {
                checker[arr[x + dx[i]][y + dy[i]]] = true;
                dum = flag + 1;
            }
            res = min(res, dum + dfs(x + dx[i], y + dy[i], checker));
        }
    }

    vis[x][y] = false;

    return res;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t;

    // cin >> t;
    scanf("%d", &t);

    while (t--)
    {
        // cin >> n;
        scanf("%d", &n);

        REP(i, 0, n)
        REP(j, 0, n)
        // cin >> arr[i][j];
        scanf("%d", &arr[i][j]);

        // cin >> sx >> sy;
        // cin >> ex >> ey;
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &ex, &ey);

        cout << dfs(sx, sy) << endl;
    }

    return 0;
}