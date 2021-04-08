#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 501
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll reqSum;
ll dp[501][62627];

ll fun(int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    else if (sum >= n)
    {
        return dp[n][sum] = (fun(n - 1, sum - n) + fun(n - 1, sum)) % mod;
    }
    else
    {
        return dp[n][sum] = fun(n - 1, sum) % mod;
    }
}

ll binExp(ll a = 2, ll power = mod - 2)
{
    ll res = 1;

    while (power)
    {
        if(power & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        power >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    reqSum = (n * (n + 1)) / 2;

    if (reqSum % 2)
    {
        cout << 0;
        return;
    }

    reqSum /= 2;

    // cout << binExp() << endl;

    memset(dp, -1, sizeof(dp));
    cout << (fun(n, reqSum) * 500000004) % mod;
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