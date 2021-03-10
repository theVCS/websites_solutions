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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m, k;
char arr[maxN][maxN];
int dist[maxN][maxN];

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == '#')
        return false;
    return true;
}

void bfs(int x, int y)
{
    deque<pii> q;
    q.push_back({x, y});
    dist[x][y] = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop_front();

        REP(i, 0, 4)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y))
            {
                if (dist[X][Y] > dist[x][y])
                {
                    dist[X][Y] = dist[x][y] + 1;
                    q.push_back({X, Y});
                }

                int _X = X + dx[i];
                int _Y = Y + dy[i];
                int _k = k - 1;

                while (_k && isValid(_X, _Y) && dist[_X][_Y] > dist[X][Y])
                {
                    dist[_X][_Y] = dist[X][Y];
                    q.push_back({_X, _Y});
                    _X = X + dx[i];
                    _Y = Y + dy[i];
                    _k--;
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> k;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];
            dist[i][j] = INF;
        }
    }

    int sx, sy, ex, ey;

    cin >> sx >> sy;
    cin >> ex >> ey;

    bfs(sx, sy);

    if (dist[ex][ey] == INF)
        cout << -1;
    else
        cout << dist[ex][ey];
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