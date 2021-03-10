#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 41
#define endl "\n"
#define INF 10001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char arr[maxN][maxN];
int dis[maxN][maxN];
int n, m, k;

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == '#')
        return false;
    return true;
}

void bfs(deque<pii> q)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        REP(i, 0, 4)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y))
            {
                if (arr[X][Y] == 's')
                {
                    if (dis[X][Y] > dis[x][y] + 1)
                    {
                        dis[X][Y] = dis[x][y] + 1;
                        q.push_back({X, Y});
                    }
                }
                else
                {
                    if (dis[X][Y] > dis[x][y])
                    {
                        dis[X][Y] = dis[x][y];
                        q.push_front({X, Y});
                    }
                }
            }
        }
    }
}

void solve()
{
    deque<pii> q;
    int ex, ey;

    // scanf("%d %d %d", &n, &m, &k);
    cin >> n >> m >> k;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];
            dis[i][j] = INF;

            if (arr[i][j] == 'x')
                ex = i, ey = j;
            else if (arr[i][j] == '@')
            {
                q.push_back({i, j});
                dis[i][j] = 0;
            }
        }
    }

    bfs(q);

    // REP(i, 1, n + 1)
    // {
    //     REP(j, 1, m + 1)
    //     cout << dis[i][j] << " ";
    //     cout << endl;
    // }

    if (2 * dis[ex][ey] <= k)
        printf("SUCCESS");
    else
        printf("IMPOSSIBLE");
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