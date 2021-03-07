#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 501
#define all(x) (x).begin(), (x).end()
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m;
int arr[maxN][maxN];
bool vis[maxN][maxN];

struct info
{
    int x, y, steps;

    info(int _x, int _y, int s)
    {
        x = _x, y = _y, steps = s;
    }
};

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y])
        return false;
    return true;
}

void solve()
{
    int maxV = INT_MIN;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];
            maxV = max(maxV, arr[i][j]);
            vis[i][j] = false;
        }
    }

    queue<info> q;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (arr[i][j] == maxV)
            {
                info e = info(i, j, 0);
                q.push(e);
                vis[i][j] = true;
            }
        }
    }

    int res = 0;

    while (!q.empty())
    {
        info node = q.front();
        q.pop();
        int x = node.x;
        int y = node.y;

        REP(i, 0, 8)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y))
            {
                info e = info(X, Y, node.steps + 1);
                q.push(e);
                vis[X][Y] = true;
                res = node.steps + 1;
            }
        }
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}