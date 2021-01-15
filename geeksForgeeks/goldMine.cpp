#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

int arr[1001][1001], n, m;
int t[1001][1001];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
    {
        return false;
    }
    return true;
}

int collector(int x, int y)
{
    if (t[x][y])
    {
        return t[x][y];
    }

    int res = 0;

    for (int i = 0; i < 3; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            res = max(res, collector(x + dx[i], y + dy[i]));
        }
    }
    return t[x][y] = res + arr[x][y];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res = 0;

    cin >> n >> m;

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    cin >> arr[i][j];

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            res = max(collector(i, j), res);
        }
    }

    cout << res;

    return 0;
}

// 3 3
// 1 3 3
// 2 1 4
// 0 6 4

// 4 4
// 1 3 1 5
// 2 2 4 1
// 5 0 2 3
// 0 6 1 2