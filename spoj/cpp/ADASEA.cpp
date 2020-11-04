#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};

ll m, n;
char arr[maxN][maxN];
bool vis[maxN][maxN];

bool isValid(ll x, ll y)
{
    if (x < 1 || y < 1 || x > m || y > n || vis[x][y] || arr[x][y] == '~')
    {
        return false;
    }
    return true;
}

ll dfs(ll x, ll y)
{
    ll cnt = 1;
    vis[x][y] = true;

    for (ll i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            cnt += dfs(x + dx[i], y + dy[i]);
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    ll res1, res2, gd;

    cin >> t;

    while (t--)
    {
        cin >> m >> n;
        res1 = 0;
        queue<ll> q;

        REP(i, 1, m + 1)
        {
            REP(j, 1, n + 1)
            {
                vis[i][j] = false;
            }
        }

        REP(i, 1, m + 1)
        {
            REP(j, 1, n + 1)
            {
                cin >> arr[i][j];
            }
        }

        REP(i, 1, m + 1)
        {
            REP(j, 1, n + 1)
            {
                if (isValid(i, j))
                {
                    q.push(dfs(i, j));
                }
            }
        }

        ll count = q.size();
        for (ll i = 0; i < count; i++)
        {
            res1 += 1LL * q.front() * q.front();
            q.pop();
        }

        res2 = 1LL * m * n;

        gd = __gcd(res1, res2);

        if ((res2 / gd) == 1)
        {
            cout << res1 / gd << endl;
        }
        else
        {
        cout << res1 / gd << " / " << res2 / gd << endl;
        }
    }

    return 0;
}