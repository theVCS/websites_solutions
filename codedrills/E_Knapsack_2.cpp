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

int weight[maxN];
int val[maxN];
int dp[100][maxN];

bool fun(int n, int prof = 100001)
{
    REP(i, 0, n + 1)
    dp[i][0] = 0;

    dp[1][val[1]] = weight[1];

    REP(i, 1, n + 1)
    {
        REP(j, 1, prof)
        {
            if (val[i] <= j)
            {
                dp[i][j] = min(weight[i] + dp[i - 1][j - val[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

void solve()
{
    int n, w;
    cin >> n >> w;

    REP(i, 1, n + 1)
    {
        cin >> weight[i] >> val[i];
    }

    memset(dp, INF, sizeof(dp));

    fun(n);

    int res = 0;

    REP(i, 0, 100001)
    {
        if (dp[n][i] <= w)
            res = i;
    }

    cout << res;
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