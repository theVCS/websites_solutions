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
#define maxN 5001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;
int n;

ll hash1[maxN];
ll hash2[maxN];
ll powers[maxN];

void init()
{
    ll power = 103, p = 103;
    hash1[0] = (s[0] - 'a' + 1);
    hash2[0] = (s[n - 1] - 'a' + 1);
    powers[0] = 1;

    REP(i, 1, n - 1)
    {
        hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * power) % mod;
        hash2[i] = (hash2[i - 1] + (s[n - 1 - i] - 'a' + 1) * power) % mod;
        powers[i] = power;
        power = (power * p) % mod;
    }
}

bool isPallindrome(int l, int r)
{
    ll res1 = hash1[r];
    if (l)
        res1 = (res1 - hash1[l - 1] + mod) % mod;

    int l1 = n - 1 - r;
    int r1 = n - 1 - l;

    ll res2 = hash2[r1];
    if (l1 > 0)
        res2 = (res2 - hash2[l1 - 1] + mod) % mod;

    if (l > l1)
    {
        return res1 == (res2 * powers[l - l1]) % mod;
    }
    else
    {
        return (res1 * powers[l1 - l]) % mod == res2;
    }
}

int dp[maxN][maxN];

void solve()
{
    cin >> s;
    n = s.size();

    init();

    REP(i, 0, n - 1)
    REP(j, i, n - 1)
    {
        dp[i][j] = isPallindrome(i, j);

        if (j)
            dp[i][j] += dp[i][j - 1];
    }


    REP(j, 0, n - 1)
    {
        REP(i, 1, n - 1)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }

    int q, l, r;
    cin >> q;

    while (q--)
    {
        cin >> l >> r;
        l--, r--;

        int res = dp[r][r];

        if (l)
            res -= dp[r][l - 1];
        if (l)
            res -= dp[l - 1][r];
        if (l)
            res += dp[l - 1][l - 1];

        cout << res << endl;
    }
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