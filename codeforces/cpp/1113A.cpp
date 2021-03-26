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

int dp[maxN][maxN];

int price(int city, int fuel, int n, int v)
{
    if (city == n)
        return 0;
    else if (dp[city][fuel] != -1)
        return dp[city][fuel];
    else
    {
        int mn = INF;

        int i = 0;

        if (fuel == 0)
            i = 1;

        while (fuel + i <= v)
        {
            mn = min(mn, city * i + price(city + 1, fuel + i - 1, n, v));
            i++;
        }

        return dp[city][fuel] = mn;
    }
}

void solve()
{
    int n, v;
    cin >> n >> v;

    memset(dp, -1, sizeof(dp));

    cout << price(1, 0, n, v);
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