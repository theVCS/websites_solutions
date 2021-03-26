#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 31
#define INF 0x3f3f3f3f
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int n, m, c;
char arr[maxN][maxN];
int cost[maxN];
ll price;

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == '$')
        return false;
    return true;
}

bool reached;

bool escaped(int x, int y)
{
    if (x == 1 || y == 1 || x == n || y == m)
        return reached = true;
    return false;
}

void dfs(int x, int y, int px = 0, int py = 0, int ct = 1000000)
{
    // finding minimum cost
    if (ct > cost[arr[x][y] - 'a'])
    {
        ct = cost[arr[x][y] - 'a'];
        px = x;
        py = y;
    }

    if (escaped(x, y))
    {
        arr[px][py] = '$';
        price += cost[arr[px][py] - 'a'];
        return;
    }

    REP(i, 0, 4)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (isValid(X, Y))
        {
            dfs(X, Y, px, py, ct);

            if (reached)
                return;
        }
    }
}

void solve()
{
    cin >> n >> m >> c;

    int sx, sy, cnt = 0;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'B')
                sx = i, sy = j;
            else if (arr[i][j] != '.')
                cnt++;
        }
    }

    REP(i, 0, c)
    cin >> cost[i];

    while (true)
    {
        reached = false;

        dfs(sx, sy);
        cnt--;

        if (reached == false || cnt == 0)
            break;
    }

    // if(reached == false)cout << price;
    // else cout << -1;
    cout << price;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}