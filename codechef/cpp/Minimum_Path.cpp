#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1005
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int cost[maxN][maxN];
char ch[maxN][maxN];
int dp[maxN][maxN];

void solve()
{
    int n, m;
    cin >> n >> m;

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    cin >> cost[i][j];

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    cin >> ch[i][j];

    REP(i, 1, n + 2)
    dp[i][m + 1] = INF;
    REP(i, 1, m + 2)
    dp[n + 1][i] = INF;

    dp[n + 1][m] = dp[n][m + 1] = 0;

    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp[i][j] = cost[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[1][1] << endl;

    string path;

    int i = 1, j = 1;

    while (i != n || j != m)
    {
        path.push_back(ch[i][j]);

        if (dp[i][j + 1] == dp[i + 1][j])
        {
            if (ch[i][j + 1] < ch[i + 1][j])
                j++;
            else
                i++;
        }
        else if (dp[i][j + 1] < dp[i + 1][j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    path.push_back(ch[i][j]);

    cout << path << endl;
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