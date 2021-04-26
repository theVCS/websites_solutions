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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;
ll dp[10][60][60][2];

int isPrime(ll even, ll odd, int n)
{
    ll diff = -1;

    if (n % 2 == 0)
        diff = even - odd;
    else
        diff = odd - even;

    return diff == 1;
}

ll fun(int n = 0, ll even = 0, ll odd = 0, int tight = 1)
{
    if (n == s.size())
    {
        return isPrime(even, odd, n);
    }
    else if (dp[n][even][odd][tight] != -1)
    {
        return dp[n][even][odd][tight];
    }
    else if (tight)
    {
        ll res = 0;

        REP(i, 0, s[n] - '0')
        {
            ll ev = even, od = odd;

            if (n % 2)
                od += i;
            else
                ev += i;

            res += fun(n + 1, ev, od, i == (s[n] - '0'));
        }

        return dp[n][even][odd][tight] = res;
    }
    else
    {
        ll res = 0;
        REP(i, 0, 9)
        {
            ll ev = even, od = odd;

            if (n % 2)
                od += i;
            else
                ev += i;

            res += fun(n + 1, ev, od, 0);
        }

        return dp[n][even][odd][tight] = res;
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    l--;

    memset(dp, -1, sizeof(dp));
    s = to_string(r);
    ll ans1 = fun();

    memset(dp, -1, sizeof(dp));
    s = to_string(l);
    ll ans2 = fun();

    cout << ans1 - ans2 << endl;
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