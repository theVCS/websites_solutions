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
#define maxN 5001
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

int n;
ll a[maxN];
ll b[maxN];
ll sum[maxN];
ll dp[maxN][maxN];

ll reverser(int l, int r)
{
    if (l > r)
        return 0;
    else if (dp[l][r] != -1)
        return dp[l][r];
    else if (l == r)
        return dp[l][r] = a[l] * b[r];
    else
        return dp[l][r] = a[l] * b[r] + a[r] * b[l] + reverser(l + 1, r - 1);
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> a[i];
    }

    REP(i, 1, n)
    {
        cin >> b[i];
        sum[i] = sum[i - 1] + a[i] * b[i];
    }

    memset(dp,-1,sizeof(dp));
    ll ans = sum[n];

    REP(i,1,n)
    {
        REP(j,i+1,n)
        {
            ans = max(ans, sum[i - 1] + (sum[n] - sum[j]) + reverser(i,j));
        }
    }

    cout<<ans;
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