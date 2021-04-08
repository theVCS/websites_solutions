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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int dp[101][101][11][11];

int n1, n2, k1, k2;
int ways(int type1, int type2, int sum_1 = 0, int sum_2 = 0)
{
    if (type1 == 0 && type2 == 0)
        return 1;

    if (dp[type1][type2][sum_1][sum_2] != -1)
    {
        return dp[type1][type2][sum_1][sum_2];
    }

    int ans = 0;
    // trying to place type1 soldier
    if (sum_1 < k1 && type1)
    {
        ans = ways(type1 - 1, type2, sum_1 + 1, 0);
    }

    // trying to place type2 soldier
    if (sum_2 < k2 && type2)
    {
        ans = (ans + ways(type1, type2 - 1, 0, sum_2 + 1)) % 100000000;
    }

    return dp[type1][type2][sum_1][sum_2] = ans;
}

void solve()
{
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << ways(n1, n2);
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