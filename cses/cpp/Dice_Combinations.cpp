#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll dp[maxN];

int ways(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = 0;
        dp[n] = (dp[n] + ways(n - 1)) % mod;
        dp[n] = (dp[n] + ways(n - 2)) % mod;
        dp[n] = (dp[n] + ways(n - 3)) % mod;
        dp[n] = (dp[n] + ways(n - 4)) % mod;
        dp[n] = (dp[n] + ways(n - 5)) % mod;
        dp[n] = (dp[n] + ways(n - 6)) % mod;

        return dp[n];
    }
}

void solve()
{
    int n;

    cin >> n;

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    cout << ways(n);
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