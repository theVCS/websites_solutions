#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int t, k;
int dp[maxN];

int ways(int flowers = maxN - 1)
{
    if (flowers < 0)
        return 0;
    else if (flowers == 0)
        return 1;
    else if (dp[flowers] != -1)
    {
        return dp[flowers];
    }
    else
    {
        return dp[flowers] = (ways(flowers - k) + ways(flowers - 1)) % mod;
    }
}

void solve()
{
    cin >> t >> k;
    memset(dp, -1, sizeof(dp));

    int ans = ways();
    int a, b;

    REP(i, 1, maxN)
    dp[i] = (dp[i] + dp[i - 1]) % mod;

    while (t--)
    {
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + mod) % mod << endl;
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}