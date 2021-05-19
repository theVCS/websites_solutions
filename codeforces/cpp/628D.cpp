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

int m, d;
ll dp[2001][2000][2];

ll fun(string &str, int n = 0, int rem = 0, int tight = 1)
{
    if (n == str.size())
    {
        return rem == 0;
    }
    else if (dp[n][rem][tight] != -1)
    {
        return dp[n][rem][tight];
    }
    else if (tight)
    {
        ll res = 0;
        int val = str[n] - '0';

        if (n & 1)
        {
            if (val >= d)
                res = (res + fun(str, n + 1, (rem * 10 + d) % m, (val == d))) % mod;
        }
        else
        {
            REP(i, 0, val)
            {
                if (i == d)
                {
                    continue;
                }

                res = (res + fun(str, n + 1, (rem * 10 + i) % m, (i == val))) % mod;
            }
        }

        return dp[n][rem][tight] = res;
    }
    else
    {
        ll res = 0;

        if (n & 1)
        {
            res = (res + fun(str, n + 1, (rem * 10 + d) % m, 0)) % mod;
        }
        else
        {
            REP(i, 0, 9)
            {
                if (i == d)
                {
                    continue;
                }

                res = (res + fun(str, n + 1, (rem * 10 + i) % m, 0)) % mod;
            }
        }

        return dp[n][rem][tight] = res;
    }
}

bool check(string &s)
{
    REP(i, 0, s.size() - 1)
    {
        if ((i % 2 == 0 && s[i] == char('0' + d)) || (i % 2 && s[i] != char('0' + d)))
        {
            return false;
        }
    }

    ll rem = 0;

    for (char c : s)
    {
        rem = (rem * 10 + (c - '0')) % m;
    }

    return (rem == 0);
}

void solve()
{
    cin >> m >> d; // num %m == 0 && d-magical

    string l, r;
    cin >> l;
    cin >> r;

    memset(dp, -1, sizeof(dp));
    ll ans1 = fun(r);

    memset(dp, -1, sizeof(dp));
    ll ans2 = fun(l);

    int cnt = 0;

    if (check(l))
        cnt = 1;

    cout << (ans1 - ans2 + cnt + mod) % mod << endl;
    // cout<<ans1<<" "<<ans2<<endl;
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