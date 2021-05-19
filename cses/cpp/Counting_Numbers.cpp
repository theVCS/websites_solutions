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

string s;
ll dp[19][11][2][2];

ll fun(int index = 0, int prev_dig = 10, int tight = 1, int start_zero = true)
{
    if (index == s.size())
        return 1;
    else if (dp[index][prev_dig][tight][start_zero] != -1)
        return dp[index][prev_dig][tight][start_zero];
    else if (tight)
    {
        ll res = 0;

        REP(i, 0, s[index] - '0')
        {
            if (start_zero && i == 0)
                res += fun(index + 1, 0, ((s[index] - '0') == i), true);
            else if (i == prev_dig)
                continue;
            else
                res += fun(index + 1, i, ((s[index] - '0') == i), false);
        }

        return dp[index][prev_dig][tight][start_zero] = res;
    }
    else
    {
        ll res = 0;

        REP(i, 0, 9)
        {
            if (start_zero && i == 0)
                res += fun(index + 1, 0, false, true);
            else if (i == prev_dig)
                continue;
            else
                res += fun(index + 1, i, false, false);
        }

        return dp[index][prev_dig][tight][start_zero] = res;
    }
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    a--;

    memset(dp, -1, sizeof(dp));
    s = to_string(b);
    ll res = fun();

    if (a >= 0)
    {
        memset(dp, -1, sizeof(dp));
        s = to_string(a);
        res -= fun();
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