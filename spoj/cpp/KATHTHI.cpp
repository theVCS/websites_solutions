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
#define all(x) (x).begin(), (x).end()
# define INF 0x3f3f3f3f 
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char mp[maxN][maxN];
int dist[maxN][maxN];
int r, c;

bool isValid(int x, int y)
{
    if (x < 1 || x > r || y < 1 || y > c)
        return false;
    return true;
}

void bfs()
{
    deque<pii> q;
    q.push_back({1, 1});
    dist[1][1] = 0;
    // vis[1][1] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        REP(i, 0, 4)
        {
            int X = x + dx[i], Y = y + dy[i];

            if (isValid(X, Y))
            {

                if (mp[X][Y] == mp[x][y])
                {
                    if (dist[X][Y] > dist[x][y])
                    {
                        dist[X][Y] = dist[x][y];

                        q.push_front({X, Y});
                    }
                }
                else
                {
                    if (dist[X][Y] > dist[x][y] + 1)
                    {
                        dist[X][Y] = dist[x][y] + 1;

                        q.push_back({X, Y});
                    }
                }
            }
        }
    }
}

void solve()
{
    // cin >> r >> c;
    scanf("%d %d", &r, &c);

    REP(i, 1, r + 1)
    {
        REP(j, 1, c + 1)
        {
            dist[i][j] = 10000;
            cin >> mp[i][j];
        }
    }

    bfs();

    printf("%d\n", dist[r][c]);
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        // solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}