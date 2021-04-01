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

void fun(string s, string t, int n, int m)
{
    int dp[n + 1][m + 1];

    REP(i, 0, n + 1)
    dp[i][0] = 0;
    REP(i, 0, m + 1)
    dp[0][i] = 0;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string res;

    int i = n, j = m;

    while (i && j)
    {
        if (s[i - 1] == t[j - 1])
        {
            res.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    reverse(all(res));

    cout << res;
}

void solve()
{
    string s, t;
    int n, m;

    cin >> s >> t;
    n = s.size();
    m = t.size();

    fun(s, t, n, m);
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