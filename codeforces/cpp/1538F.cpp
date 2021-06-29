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
ll dp[20][2];

ll fun(int index = 0, int tight = 1)
{
    if (index == s.size())
    {
        return 0;
    }
    else if (dp[index][tight] != -1)
    {
        return dp[index][tight];
    }
    else if (tight)
    {
        int ub = (s[index] - '0');
        return dp[index][tight] = (ub * fun(index + 1, 0) + ub) + fun(index + 1, 1);
    }
    else
    {
        return dp[index][tight] = 10 * fun(index + 1, 0) + 10;
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;

    ll ans;
    s = to_string(r);
    memset(dp, -1, sizeof(dp));
    ans = fun();
    // cout<<fun()<<endl;

    s = to_string(l);
    memset(dp, -1, sizeof(dp));
    ans -= fun();
    // cout<<fun()<<endl;

    cout<<ans<<endl;
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