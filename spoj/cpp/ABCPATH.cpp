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

int n, m, len;
char arr[51][51];
int mem[51][51];

bool isValid(int x, int y, char c)
{
    if (x < 1 || y < 1 || x > n || y > m || arr[x][y] != c + 1)
    {
        return false;
    }
    return true;
}

int dfs(int x, int y)
{
    int res = 0;

    if (mem[x][y])
    {
        return mem[x][y];
    }

    for (int i = 0; i < 8; i++)
    {
        if (isValid(x + dx[i], y + dy[i], arr[x][y]))
        {
            res = max(dfs(x + dx[i], y + dy[i]), res);
        }
    }

    return (mem[x][y] = res + 1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res, t = 1;

    while (true)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            return 0;
        }

        res = 0;
        REP(i, 1, n + 1)
        {
            REP(j, 1, m + 1)
            {
                mem[i][j] = 0;
            }
        }

        vector<pair<int, int>> src;

        REP(i, 1, n + 1)
        {
            REP(j, 1, m + 1)
            {
                cin >> arr[i][j];

                if (arr[i][j] == 'A')
                {
                    src.push_back({i, j});
                }
            }
        }

        for (pair<int, int> e : src)
        {
            res = max(res, dfs(e.first, e.second));
        }

        cout << "Case " << t << ": " << res << endl;
        t++;
    }

    return 0;
}