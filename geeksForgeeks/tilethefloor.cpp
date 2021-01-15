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

ll dp[1001];

ll count(int n, int m)
{
    if (n < 0)
    {
        return 0;
    }
    else if (dp[n] != -1)
    {
        return dp[n];
    }
    else if (n < m)
    {
        return dp[n] = 1;
    }
    else
    {
        return dp[n] = count(n - 1, m) + count(n - m, m);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;

    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        cout << count(n, m) << endl;
    }

    return 0;
}