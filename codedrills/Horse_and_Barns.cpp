#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

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

queue<pii> q;
int d[maxN][maxN];
int n, m;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        REP(i, 0, 7)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y))
            {
                if (d[X][Y] > d[x][y] + 1)
                {
                    d[X][Y] = d[x][y] + 1;
                    q.push({X, Y});
                }
            }
        }
    }
}

ll mod_power(ll x, ll y, ll mod)
{
    ll ans = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans % mod) * (x % mod)) % mod;

        y = y >> 1;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return ans;
}

//----------------------------------------------- //
// Initiate mod_fac() function first

ll fac[1000005];
void mod_fac()
{
    fac[0] = 1;
    for (ll i = 1; i < 1000005; i += 1)
        fac[i] = (fac[i - 1] * i) % mod;
}
ll mod_inverse(ll n)
{
    return mod_power(n, mod - 2, mod);
}
ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    ll res = fac[n];
    res = (res * mod_inverse(fac[r], mod)) % mod;
    res = (res * mod_inverse(fac[n - r], mod)) % mod;
    return res % mod;
}
void solve()
{
    int k;
    char c;

    cin >> n >> m >> k;

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            cin >> c;

            if (c == 'X')
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = INF;
            }
            q.push({i, j});
        }
    }

    bfs();

    ll modInv = binExp(n * m, mod - 2) * k;
    ll sum = 0;

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            prefix[d[i][j]]++;
        }
    }

    ll ways = 0;

    REP(i, 1, 6000)
    {
        int x = prefix[i];
        int y = prefix[i - 1];
        prefix[i] += prefix[i - 1];

        if (x == 0 || (x + y < k))
            continue;

        ways = (ways + ncr(x, 1) * ncr(x + y - 1)) % mod;
    }

    // cout<<sum<<endl;

    cout << (sum * modInv) % mod << endl;
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
    mod_fac();

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}