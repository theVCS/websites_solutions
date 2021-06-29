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
// #define endl "\n"
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

int n;
string s[2];
int dp[2][200010][4];

bool fun(int i = 0, int j = 1, int d = 1)
{
    // cout<<i<<" "<<j<<" "<<d<<endl;

    if (i == 1 && j == n + 1)
        return true;

    if (i < 0 || i > 1 || j > n)
        return false;

    // if (dp[i][j][d] != -1)
    //     return dp[i][j][d];

    if (d == 1)
    {
        if (s[i][j] == '1' || s[i][j] == '2')
        {
            return dp[i][j][d] = fun(i, j + 1, 1);
        }
        else
        {
            return dp[i][j][d] = fun(i - 1, j, 2) || fun(i + 1, j, 3);
        }
    }
    else if (d == 2)
    {
        if (s[i][j] == '1' || s[i][j] == '2')
        {
            return dp[i][j][d] = fun(i - 1, j, 2);
        }
        else
        {
            return dp[i][j][d] = fun(i, j + 1, 1);
        }
    }
    else
    {
        if (s[i][j] == '1' || s[i][j] == '2')
        {
            return dp[i][j][d] = fun(i + 1, j, 3);
        }
        else
        {
            return dp[i][j][d] = fun(i, j + 1, 1);
        }
    }
}

void solve()
{
    cin >> n;
    cin >> s[0] >> s[1];

    s[0].insert(0, "0");
    s[1].insert(0, "0");

    // REP(i, 0, n)
    // {
    //     dp[i][0][1] = -1;
    //     dp[i][0][2] = -1;
    //     dp[i][0][3] = -1;

    //     dp[i][1][1] = -1;
    //     dp[i][1][2] = -1;
    //     dp[i][1][3] = -1;
    // }

    if (fun())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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