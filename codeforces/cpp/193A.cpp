#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 51
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m;
char arr[maxN][maxN];
bool vis[maxN][maxN];
int cnt;

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || arr[x][y] == '.')
        return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    cnt++;

    REP(i, 0, 4)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

void solve()
{
    cin >> n >> m;

    int acnt = 0;

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    {
        cin >> arr[i][j];

        if (arr[i][j] == '#')
            acnt++;
    }

    if (acnt == 0)
    {
        cout << 0;
        return;
    }

    if (n * m <= 2 || acnt == 1)
    {
        cout << -1;
        return;
    }

    if (n == 1 || m == 1)
    {
        cout << 1;
        return;
    }

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    {
        if (arr[i][j] == '#')
        {
            cnt = 0;
            memset(vis, false, sizeof(vis));

            REP(k, 0, 4)
            {
                if (isValid(i + dx[k], j + dy[k]))
                {
                    arr[i][j] = '.';
                    dfs(i + dx[k], j + dy[k]);
                    arr[i][j] = '#';
                    break;
                }
            }

            if (acnt - 1 != cnt)
            {
                cout << 1;
                return;
            }
        }
    }

    cout << 2;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}