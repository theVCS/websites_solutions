#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 9
#define all(x) (x).begin(), (x).end()
#define endl "\n"

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int steps[maxN][maxN];
bool vis[maxN][maxN];
bool flag;

bool isValid(int x, int y)
{
    if (x < 1 || x > 8 || y < 1 || y > 8 || vis[x][y])
        return false;
    return true;
}

void dfs(int x, int y, int step = 1)
{
    vis[x][y] = true;
    steps[x][y] = step;

    if (step == 64)
    {
        flag = true;
        return;
    }

    REP(i, 0, 8)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i], step + 1);

            if (flag)
                return;
        }
    }

    vis[x][y] = false;
}

void solve()
{
    int x, y;

    cin >> y >> x;

    dfs(x, y);

    int maxStep = 0;

    REP(i, 1, 9)
    {
        REP(j, 1, 9)
        {
            cout << steps[i][j] << " ";
            maxStep = max(maxStep, steps[i][j]);
        }
        cout << endl;
    }

    cout << maxStep;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}