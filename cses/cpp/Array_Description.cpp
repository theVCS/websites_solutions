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
#define INF 1000000000
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int arr[maxN];
ll dp[111][maxN+10];

void solve()
{
    int n, x;
    cin >> n >> x;

    REP(i, 1, n + 1)
    cin >> arr[i];

    REP(i, 1, n + 1)
    {
        if (i == 1)
        {
            if (arr[i] == 0)
                REP(j, 1, x + 1)
                {
                    dp[j][i] = 1;
                }
            else
                dp[arr[i]][i] = 1;
            continue;
        }

        if (arr[i] == 0)
        {
            REP(j, 1, x + 1)
            {
                dp[j][i] = (dp[j - 1][i - 1] + (dp[j][i - 1] + dp[j + 1][i - 1]) % mod) % mod;
            }
        }
        else
        {
            dp[arr[i]][i] = ((dp[arr[i] - 1][i - 1] + dp[arr[i]][i - 1]) % mod + dp[arr[i] + 1][i - 1]) % mod;
        }
    }

    ll ways = 0;

    if (arr[n] == 0)
    {
        REP(i, 1, x + 1)
        ways = (ways + dp[i][n]) % mod;
    }
    else
    {
        ways = dp[arr[n]][n];
    }
    cout << ways;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}