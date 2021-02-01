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

int n, k;
int dp[100001][101];

int change(int n, int pos)
{
    int tenp = 1;

    while (pos--)
    {
        tenp *= 10;
    }

    int dig = int(n / tenp) % 10;

    if (dig == 9)
    {
        n -= 9 * tenp;
    }
    else
    {
        n += tenp;
    }
    return n;
}

int solve(int n, int t, int k)
{
    if (t > k)
    {
        return n;
    }
    else if (dp[n][t] != -1)
    {
        return dp[n][t];
    }
    else
    {
        int ans, newn;

        if (t % 2)
        {
            ans = 0;
            for (int i = 0; i < 4; i++)
            {
                newn = change(n, i);
                ans = max(ans, solve(newn, t + 1, k));
            }
        }
        else
        {
            ans = INT_MAX;
            for (int i = 0; i < 4; i++)
            {
                newn = change(n, i);
                ans = min(ans, solve(newn, t + 1, k));
            }
        }
        return dp[n][t] = ans;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, res;

    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        res = solve(n, 1, k);

        // cout << res;

        if (res > n)
        {
            cout << "Ada" << endl;
        }
        else
        {
            cout << "Vinit" << endl;
        }
    }

    return 0;
}