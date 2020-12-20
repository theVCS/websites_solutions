#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int dp[maxN][2];

int bossKiller(int arr[], int n, int c = 1)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (dp[n][c] != -1)
    {
        return dp[n][c];
    }
    else if (c == 1)
    {
        return dp[n][c] = min(arr[n - 1] + bossKiller(arr, n - 1, c ^ 1), arr[n - 1] + arr[n - 2] + bossKiller(arr, n - 2, c ^ 1));
    }
    else
    {
        return dp[n][c] = min(bossKiller(arr, n - 1, c ^ 1), bossKiller(arr, n - 2, c ^ 1));
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        int arr[n];

        for (int i = n - 1; i > -1; i--)
        {
            dp[i + 1][0] = -1;
            dp[i + 1][1] = -1;
            cin >> arr[i];
        }

        cout << bossKiller(arr, n) << endl;
    }

    return 0;
}