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

ll dp[51][17][17][2];

ll fun(string &s, int n = 0, int s_3 = 0, int s_6 = 0, int s_9 = 0, int tight = 1)
{
    if ((s_3 > (s.size() / 3)) || (s_6 > (s.size() / 3)) || (s_9 > (s.size() / 3)))
    {
        return 0;
    }
    else if (n == s.size())
    {
        return s_3 && (s_3 == s_6) && (s_6 == s_9);
    }
    else if (dp[n][s_3][s_6][s_9][tight] != -1)
    {
        return dp[n][s_3][s_6][s_9][tight];
    }
    else if (tight)
    {
        ll res = 0;
        REP(i, 0, s[n] - '0')
        {
            res = (res + fun(s, n + 1, (s_3 + i == 3), (s_6 + i == 6), (s_9 + i == 9), i == (s[n] - '0'))) % mod;
        }
        return dp[n][s_3][s_6][s_9][tight] = res;
    }
    else
    {
        ll res = 0;

        REP(i, 0, 9)
        {
            res = (res + fun(s, n + 1, (s_3 + i == 3), (s_6 + i == 6), (s_9 + i == 9), 0)) % mod;
        }

        return dp[n][s_3][s_6][s_9][tight] = res;
    }
}

void solve()
{
    string l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    ll res1 = fun(r);

    memset(dp, -1, sizeof(dp));
    ll res2 = fun(l);

    cout << res1 - res2 << endl;
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
