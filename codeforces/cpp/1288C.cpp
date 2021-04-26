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

int n, m;
ll dp[1001][1001][11];

ll ways(int m, int a_max, int b_min)
{
    if (a_max > b_min)
        return 0;
    if (m == 0)
    {
        return 1;
    }
    else if (dp[a_max][b_min][m] != -1)
    {
        return dp[a_max][b_min][m];
    }
    else
    {
        ll ans = 0;

        RREP(j, b_min, 1)
        {
            REP(i, a_max, j)
            {
                ans = (ans + ways(m - 1, i, j)) % mod;
            }
        }

        return dp[a_max][b_min][m] = ans;
    }
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << ways(m, 1, n);
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