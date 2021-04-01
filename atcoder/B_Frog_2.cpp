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

int n, k;
int arr[maxN];
int dp[maxN];

void solve()
{
    cin >> n >> k;

    REP(i, 1, n + 1)
    cin >> arr[i],
        dp[i] = -1;

    dp[n] = 0;

    for (int i = n - 1; i > 0; i--)
    {
        int res = INT_MAX;

        REP(j, 1, k + 1)
        {
            if (i + j > n)
                break;
            res = min(res, abs(arr[i] - arr[j + i]) + dp[i + j]);
        }

        dp[i] = res;
    }

    cout << dp[1];
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