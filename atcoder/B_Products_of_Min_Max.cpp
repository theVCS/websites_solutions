#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 998244353
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define endl "\n"
#define INF 10000000000000000
#define NINF -10000000000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll dp[maxN];

ll fun(int n, ll mn = INF, ll mx = NINF)
{
    if (n == 0)
    {
        if (mn != INF)
            return (mn * mx) % mod;
        return 0;
    }
    else if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        return dp[n] = (fun(n - 1, mn, mx) + fun(n - 1, mn, max(mx, arr[n]))) % mod;
    }
}

void solve()
{
    int n;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        dp[i] = -1;
    }

    cout << fun(n, arr[1]);
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