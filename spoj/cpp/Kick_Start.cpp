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
ll dp[20][2];

ll fun(int n = 0, int tight = 1)
{
    if (n == s.size())
    {
        return n;
    }
    else if (dp[n][tight] != -1)
    {
        return dp[n][tight];
    }
    else if (tight)
    {
        ll res = 0;

        for (int i = (n + 1) % 2; i <= s[n] - '0'; i += 2)
        {
            if (i == s[n] - '0')
            {
                res += fun(n + 1, 1);
            }
            else
            {
                res += fun(n + 1, 0);
            }
        }

        return dp[n][tight] = res;
    }
    else
    {
        ll res = 0;

        for (int i = (n + 1) % 2; i <= 9; i += 2)
            res += fun(n + 1, 0);

        return dp[n][tight] = res;
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    l--;

    s = to_string(r);
    memset(dp, -1, sizeof(dp));
    ll ans1 = fun();

    s = to_string(l);
    memset(dp, -1, sizeof(dp));
    ll ans2 = fun();

    // cout << ans1 - ans2;
    cout << ans1 << " " << ans2;
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

    REP(i, 1, t)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }

    //filptr.close();
    //outpter.close();

    return 0;
}