#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int subCount(ll arr[], ll sum, int n)
{
    int dp[n + 1][sum + 1];

    REP(i, 0, sum + 1)
    {
        dp[0][i] = 0;
    }

    REP(i, 0, n + 1)
    {
        dp[i][0] = 1;
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, k;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        ll arr[n];
        ll sum = 0;

        REP(i, 0, n)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if ((sum % k == 0) && (k <= subCount(arr, (sum / k), n)))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}