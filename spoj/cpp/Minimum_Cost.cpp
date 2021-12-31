#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1}
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// size of object b
const int sz = 1001;
int dp[sz][2];

// caution --- for numbers use vector starting at index 0 and for characters use string
template <class T>
class LongestCommonSubsequence
{
public:
    // returns length of longest common subsequence (memory efficient)
    int lcs(T &a, T &b)
    {
        int n = a.size();
        int m = b.size();

        REP(i, 0, m)
        dp[i][0] = dp[i][1] = 0;

        REP(i, 1, n)
        REP(j, 1, m)
        {
            int p = (i & 1);

            if (a[i - 1] == b[j - 1])
                dp[j][p] = 1 + dp[j - 1][p ^ 1];
            else
                dp[j][p] = max(dp[j - 1][p], dp[j][p ^ 1]);
        }

        return dp[m][n & 1];
    }
};

void solve()
{
    while (true)
    {
        string a, b;
        
        cin >> a;
        if (a == "#")return;
        cin >> b;

        LongestCommonSubsequence<string> obj;
        int res = obj.lcs(a, b);

        cout << (a.size() - res) * 15 + (b.size() - res) * 30 << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}