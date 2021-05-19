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
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
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

int n, m, b;
int arr[201][201];
ll dp[100001];
int vec[201];
int counter[100001];

ll fun1(int index, int sum)
{
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    REP(i, 1, n)
    {
        RREP(j, b, 0)
        {
            if (vec[i - 1] <= j)
            {
                dp[j] = (dp[j] + dp[j - vec[i - 1]]) % mod;
            }
        }
    }

    return dp[b];
}

void add(vector<ll> &vec)
{
    int n = vec.size();

    REP(mask, 0, ((1 << n) - 1))
    {
        int cnt = 0;

        REP(i, 0, n - 1)
        {
            if ((1 << i) & mask)
                cnt += vec[i];
        }

        if (cnt <= b)
            counter[cnt]++;
    }
}

void remove(vector<ll> &vec)
{
    int n = vec.size();

    REP(mask, 0, ((1 << n) - 1))
    {
        int cnt = 0;

        REP(i, 0, n - 1)
        {
            if ((1 << i) & mask)
                cnt += vec[i];
        }

        if (cnt <= b)
            counter[cnt]--;
    }
}

ll fun2()
{
    vector<ll> l, r;

    REP(i, 0, n - 1)
    {
        if (i < (n / 2))
            l.push_back(vec[i]);
        else
            r.push_back(vec[i]);
    }

    add(l);

    ll res = 0;

    int n = r.size();

    REP(mask, 0, ((1 << n) - 1))
    {
        int cnt = 0;

        REP(i, 0, n - 1)
        {
            if ((1 << i) & mask)
                cnt += r[i];
        }

        if (cnt <= b)
            res = (res + counter[b - cnt]) % mod;
    }

    remove(l);

    return res;
}

void solve()
{
    cin >> n >> m >> b;

    if (n > m)
    {
        REP(i, 0, n - 1)
        REP(j, 0, m - 1)
        cin >> arr[i][j];
    }
    else
    {
        REP(i, 0, n - 1)
        REP(j, 0, m - 1)
        cin >> arr[j][i];

        swap(n, m);
    }

    ll ans = 0;
    bool mim = (m <= 5);

    REP(mask, 0, (1 << m) - 1)
    {
        REP(i, 0, n - 1)
        {
            vec[i] = 0;
            REP(j, 0, m - 1)
            {
                if (mask & (1 << j))
                    vec[i] += arr[i][j];
            }
        }

        if(mim)
            ans += fun1(n - 1, b);
        else
            ans += fun2();

        ans %= mod;
    }

    cout << ans << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}