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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void minFinder(int n)
{
    int dp[10];

    int i = 0, power = 1;

    while (n)
    {
        dp[i] = (n % 10) * power + (i > 0 ? dp[i - 1] : 0);
        n /= 10;
        power *= 10;
        i++;
    }

    int ans = INT_MAX;

    REP(k, 0, i)
    {
        int res = 0;
        if (k > 0)
            res = dp[k - 1];

        res += (dp[i - 1] - dp[k]) / 10;

        ans = min(ans, res);
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        minFinder(n);
    }

    return 0;
}