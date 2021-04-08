#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int dp[maxN][maxN][maxN];

int fun(int l, int r, int b)
{
    if (r - l <= 1)
    {
        return 0;
    }
    else if (dp[l][r][b] != -1)
    {
        return dp[l][r][b];
    }
    else
    {
        int evnCnt = 0;
        int oddCnt = 0;
        int mxCut = 0;

        REP(i, l, r)
        {
            if (arr[i] & 1)
                oddCnt++;
            else
                evnCnt++;

            // checking if evens  = odds and making cuts
            if (evnCnt == oddCnt && b >= abs(arr[i] - arr[i + 1]))
            {
                // cout << i << endl;
                mxCut = max({mxCut, 1 + fun(l, i, b - abs(arr[i] - arr[i + 1])), 1 + fun(i + 1, r, b - abs(arr[i] - arr[i + 1]))});
            }
        }

        return dp[l][r][b] = mxCut;
    }
}

void solve()
{
    int n, b;
    cin >> n >> b;

    REP(i, 1, n + 1)
    cin >> arr[i];

    memset(dp,-1,sizeof(dp));

    cout << fun(1, n, b);
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