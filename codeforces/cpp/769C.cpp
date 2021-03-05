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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string res;
int n, m, k;
char arr[maxN][maxN];
int sx, sy;

char findDire(int i)
{
    if (i == 0)
        return 'U';

    if (i == 1)
        return 'L';

    if (i == 2)
        return 'D';

    return 'R';
}

int startAround(int x, int y)
{
    REP(i, 0, 4)
    {
        if (x + dx[i] == sx && y + dy[i] == sy)
            return i;
    }

    return -1;
}

bool isValid(int x, int y)
{
    if (arr[x][y] == '*' || x < 1 || x > n || y < 1 || y > m)
        return false;

    return true;
}

void dfs(int x, int y, string s = "")
{
    if (s.size() == k)
        return;

    int around = startAround(x, y);

    if (around != -1 && s.size() == k - 1)
    {
        string str = s + findDire(around);
        res = min(res, str);
        return;
    }

    REP(i, 0, 4)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i], s + findDire(i));
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    res = "{";

    cin >> n >> m >> k;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'X')
                sx = i, sy = j;
        }
    }

    dfs(sx, sy);

    if (res == "{")
        cout << "IMPOSSIBLE";
    else
        cout << res;

    return 0;
}