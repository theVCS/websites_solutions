#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
char arr[maxN][maxN];
int dp[maxN][maxN];

void solve()
{
    cin >> n;

    REP(i, 1, n + 1)
    REP(j, 1, n + 1)
    cin >> arr[i][j];

    if (arr[n][n] == '.')
        dp[n][n] = 1;

    for (int i = n - 1; i >= 1; i--)
    {
        if (arr[i][n] == '.')
            dp[i][n] = dp[i + 1][n];
        if (arr[n][i] == '.')
            dp[n][i] = dp[n][i + 1];
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (arr[i][j] == '.')
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
            }
        }
    }
    cout << dp[1][1];
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