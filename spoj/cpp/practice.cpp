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
//     remove(L++);3

int n;
int low, high;
ll e, o;
ll dp[maxN][2];

ll ways(int n, int odd)
{
    if (n == 0)
    {
        return odd == 0;
    }
    else if (dp[n][odd] != -1)
    {
        return dp[n][odd];
    }
    else
    {
        dp[n][0] = (o * ways(n - 1, 1) + e * ways(n - 1, 0)) % mod;
        dp[n][1] = (o * ways(n - 1, 0) + e * ways(n - 1, 1)) % mod;

        return dp[n][odd];
    }
}

void solve()
{
    cin >> n >> low >> high;

    int ele = high - low + 1;

    o = ele / 2;
    e = ele - o;

    memset(dp, -1, sizeof(dp));

    cout << ways(n, 0);
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