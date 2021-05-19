#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 26
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, m;
int arr[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];

bool check(int l1, int l2, int r1, int r2)
{
    int sum = arr[l2][r2] - arr[l2][r1 - 1] - arr[l1 - 1][r2] + arr[l1 - 1][r1 - 1];
    // return sum;
    return (sum == 0);
}

bool isValid(int l1, int l2, int r1, int r2)
{
    if (l1 > l2 || r1 > r2 || l1 > n || l2 <= 0 || r1 > m || r2 <= 0)
        return false;
    return true;
}

int fun(int l1, int l2, int r1, int r2)
{
    if (isValid(l1, l2, r1, r2) == false)
        return 0; // invalid states

    if (dp[l1][l2][r1][r2] != -1)
        return dp[l1][l2][r1][r2];

    if (check(l1, l2, r1, r2))
        return dp[l1][l2][r1][r2] = (l2 - l1 + r2 - r1 + 2) * 2;

    return dp[l1][l2][r1][r2] = max({fun(l1 + 1, l2, r1, r2), fun(l1, l2 - 1, r1, r2), fun(l1, l2, r1 + 1, r2), fun(l1, l2, r1, r2 - 1)});
}

void solve()
{

    cin >> n >> m;
    char c;

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            cin >> c;
            arr[i][j] = c - '0';
            arr[i][j] += arr[i][j - 1];
        }
    }

    REP(j, 1, m)
    {
        REP(i, 1, n)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << fun(1, n, 1, m);
    // cout << check(1, 1, 10, 10);
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