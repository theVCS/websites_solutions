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

int pages[maxN];
int price[maxN];
int dp[1001][100001];

int maxPages(int n, int mon)
{
    if(n == 0 || mon == 0)
    {
        return 0;
    }
    else if (dp[n][mon] != -1)
    {
        return dp[n][mon];
    }
    else if(mon >= price[n])
    {
        return dp[n][mon] = max(pages[n] + maxPages(n - 1, mon - price[n]), maxPages(n - 1,mon));
    }
    else
    {
        return dp[n][mon] = maxPages(n - 1,mon);
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;

    REP(i,1,n+1)cin>>price[i];
    REP(i,1,n+1)cin>>pages[i];

    REP(i,1,n+1)
    {
        REP(j,1,x+1)
        {
            if(j >= price[i])
            {
                dp[i][j] = max(pages[i] + dp[i - 1][j - price[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];    
            }
        }
    }

    cout << dp[n][x];
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