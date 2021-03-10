#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 2001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct distance
{
    int left, right;

    distance()
    {
        left = INF, right = INF;
    }
} dist[maxN][maxN];

int n, m;
char arr[maxN][maxN];

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || arr[x][y] == '*')
        return false;
    return true;
}

void bfs(int x, int y)
{
    deque<pii> q;
    q.push_back({x, y});
    dist[x][y].right = 0;
    dist[x][y].left = 0;

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
                if (i == 1)
                {
                    if (dist[X][Y].left > dist[x][y].left + 1)
                    {
                        dist[X][Y].left = dist[x][y].left + 1;
                        dist[X][Y].right = dist[x][y].right;
                        q.push_back({X, Y});
                    }
                }
                else if (i == 3)
                {
                    if (dist[X][Y].right > dist[x][y].right + 1)
                    {
                        dist[X][Y].right = dist[x][y].right + 1;
                        dist[X][Y].left = dist[x][y].left;
                        q.push_back({X, Y});
                    }
                }
                else
                {
                    if (dist[X][Y].right > dist[x][y].right || dist[X][Y].left > dist[x][y].left)
                    {
                        dist[X][Y].right = dist[x][y].right;
                        dist[X][Y].left = dist[x][y].left;
                        q.push_front({X, Y});
                    }
                }
            }
        }
    }
}

void solve()
{
    int r, c;
    int le, ri;

    cin >> n >> m;
    cin >> r >> c;
    cin >> le >> ri;

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    cin >> arr[i][j];

    bfs(r, c);

    int res = 0;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (arr[i][j] == '.' && dist[i][j].left <= le && dist[i][j].right <= ri)
                res++;
        }
    }

    cout << res;
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