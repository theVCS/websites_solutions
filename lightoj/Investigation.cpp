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

int k;
string s;
int dp[10][90][2][90];

int fun(int n = 0, int sum = 0, int tight = 1, int rem = 0)
{
    if (n == s.size())
    {
        return (rem == 0) && (sum % k == 0);
    }
    else if (dp[n][sum][tight][rem] != -1)
    {
        return dp[n][sum][tight][rem];
    }
    else if (tight)
    {
        int res = 0;

        REP(i, 0, s[n] - '0')
        {
            res += fun(n + 1, sum + i, i == (s[n] - '0'), (rem * 10 + i) % k);
        }
        return dp[n][sum][tight][rem] = res;
    }
    else
    {
        int res = 0;

        REP(i, 0, 9)
        {
            res += fun(n + 1, sum + i, 0, (rem * 10 + i) % k);
        }

        return dp[n][sum][tight][rem] = res;
    }
}

void solve()
{
    int l, r;
    cin >> l >> r >> k;

    if(k > 90)
    {
        cout<<0<<endl;
        return;
    }

    l--;

    memset(dp,-1,sizeof(dp));
    s = to_string(r);
    int ans1 = fun();

    memset(dp,-1,sizeof(dp));
    s = to_string(l);
    int ans2 = fun();

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

    REP(i, 1, t)
    {
        cout << "Case " << i << ": ";
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}