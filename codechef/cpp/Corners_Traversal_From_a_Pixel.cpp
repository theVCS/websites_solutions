#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<ll, ll>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
ll dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
ll dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

struct grid
{
    ll px;
    vector<ll> dir;
} arr[maxN][maxN];

ll n, m, s, sx, sy;
ll dist[maxN][maxN];
pii par[maxN][maxN];

bool isValid(ll x, ll y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}

void bfs(ll sx, ll sy)
{
    dist[sx][sy] = 0;
    queue<pii> q;
    q.push({sx, sy});
    par[sx][sy] = {-1, -1};

    while (!q.empty())
    {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();

        for (ll i : arr[x][y].dir)
        {
            ll X = x + dx[i];
            ll Y = y + dy[i];

            if (isValid(X, Y))
            {
                if (dist[X][Y] > dist[x][y] + 1)
                {
                    dist[X][Y] = dist[x][y] + 1;
                    par[X][Y] = {x, y};
                    q.push({X, Y});
                }
                else if (dist[X][Y] == dist[x][y] + 1 && arr[par[X][Y].first][par[X][Y].second].px > arr[x][y].px)
                {
                    par[X][Y] = {x,y};
                }
            }
        }
    }
}

void printPath(ll x, ll y)
{
    if (dist[x][y] == INF)
    {
        cout << 0 << endl;
        return;
    }

    vector<ll> res;

    while (x != -1 && y != -1)
    {
        ll X = x, Y = y;
        res.push_back(arr[x][y].px);
        x = par[X][Y].first;
        y = par[X][Y].second;
    }

    RREP(i, res.size() - 1, 0)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void solve()
{
    ll d;

    cin >> n >> m >> s;

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            dist[i][j] = INF;

            cin >> arr[i][j].px;

            if (arr[i][j].px == s)
                sx = i, sy = j;

            REP(dir, 0, 7)
            {
                cin >> d;

                if (d)
                    arr[i][j].dir.push_back(dir);
            }
        }
    }

    bfs(sx, sy);

    printPath(1, 1);
    printPath(1, m);
    printPath(n, 1);
    printPath(n, m);
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