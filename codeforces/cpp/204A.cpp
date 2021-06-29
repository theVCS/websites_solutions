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
ll dp[20][2][10][10];

ll fun(int index = 0, int tight = 1, int fd = 0, int ld = 10)
{
    if (index == s.size())
    {
        return (ld == fd);
    }
    else if(dp[index][tight][fd][ld] != -1)
    {
        return dp[index][tight][fd][ld];
    }
    else if (tight)
    {
        ll res = 0;

        REP(i, 0, s[index] - '0')
        {
            int f = 0;

            if (fd)
                f = fd;
            else if (fd == 0)
                f = i;

            res += fun(index + 1, (i == (s[index] - '0')), f, i);
        }

        return dp[index][tight][fd][ld] = res;
    }
    else
    {
        ll res = 0;

        REP(i, 0, 9)
        {
            int f = 0;

            if (fd)
                f = fd;
            else
                f = i;

            res += fun(index + 1, 0, f, i);
        }

        return dp[index][tight][fd][ld] = res;
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    l--;
    
    memset(dp,-1,sizeof(dp));
    s = to_string(r);
    ll res = fun();

    memset(dp,-1,sizeof(dp));
    s = to_string(l);
    res -= fun();

    cout<<res;
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