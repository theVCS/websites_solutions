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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int ans;

int solve(ll arr[], int n)
{
    int dp[n + 1];
    int res = 1;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        if (arr[i - 1] >= arr[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
            res = max(res, dp[i]);
        }
        else
        {
            dp[i] = 1;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp = 0;

    cin >> n;

    ll arr[n];

    REP(i, 0, n)
    cin >> arr[i];

    cout << solve(arr, n);

    return 0;
}