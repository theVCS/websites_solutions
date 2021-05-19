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

int N, M, K;
int arr[71][71];
int dp[71][71][71][71];

int fun(int n, int m, int cnt = 0, int rem = 0)
{
    if (n == 0)
    {
        if (rem == 0)
        {
            return dp[n][m][cnt][rem] = 0;
        }
        else
        {
            return dp[n][m][cnt][rem] = -INF;
        }
    }
    else if(dp[n][m][cnt][rem] != -1)
    {
        return dp[n][m][cnt][rem];
    }
    else if (m == 0)
    {
        return dp[n][m][cnt][rem] = fun(n - 1, M, 0, rem);
    }
    else if (cnt == (M / 2))
    {
        return dp[n][m][cnt][rem] = fun(n, m - 1, cnt, rem);
    }
    else
    {
        return dp[n][m][cnt][rem] = max(fun(n, m - 1, cnt, rem), arr[n][m] + fun(n, m - 1, cnt + 1, (rem + arr[n][m]) % K));
    }
}

void solve()
{
    cin >> N >> M >> K;

    REP(i, 1, N)
    {
        REP(j, 1, M)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    cout << fun(N, M);
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