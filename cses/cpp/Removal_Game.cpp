#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll dp[maxN][maxN][2];

ll fun(int l, int r, int player = 0)
{
    if (l > r)
    {
        return 0;
    }
    else if (dp[l][r][player] != -1)
    {
        return dp[l][r][player];   
    }
    else
    {
        if (player == 0)
        {
            return dp[l][r][player] = max(arr[l] + fun(l + 1, r, 1), arr[r] + fun(l, r - 1, 1));
        }
        else
        {
            return dp[l][r][player] = min(fun(l + 1, r, 0), fun(l, r - 1, 0));
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n + 1)
    cin >> arr[i];

    memset(dp,-1,sizeof(dp));

    // REP(i,1,n+1)
    // {
    //     REP(j,1,n+1)
    //     {

    //     }     
    // }

    cout << fun(1, n, 0);
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