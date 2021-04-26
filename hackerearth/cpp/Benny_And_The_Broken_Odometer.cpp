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
ll dp[11][2][2];

ll fun(int n = 0, int tight = 1, int flag = 0)
{
    if (n == s.size())
    {
        return flag;
    }
    else if (dp[n][tight][flag] != -1)
    {
        return dp[n][tight][flag];
    }
    else if (tight)
    {
        ll res = 0;

        REP(i, 0, s[n] - '0')
        {
            if (i == s[n] - '0')
            {
                res += fun(n + 1, 1, flag | i == 3);
            }
            else
            {
                res += fun(n + 1, 0, flag | i == 3);
            }
        }

        return dp[n][tight][flag] = res;
    }
    else
    {
        ll res = 0;

        REP(i, 0, 9)
        {
            res += fun(n + 1, 0, flag | i == 3);
        }

        return dp[n][tight][flag] = res;
    }
}

void solve()
{
    ll n;
    cin>>n;
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    ll res = fun();
    cout << n - res << endl;
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