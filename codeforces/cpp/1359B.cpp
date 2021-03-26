#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    int n, m, x, y;
    char dum;

    cin >> n >> m >> x >> y;

    int dp[maxN];

    dp[0] = 0;
    dp[1] = x;

    REP(i,2,m+1)
    {
        dp[i] = min(x+dp[i - 1], y + dp[i - 2]);
    }

    int res = 0;
    int cnt = 0;

    REP(i,1,n+1)
    {
        cnt = 0;

        REP(j,1,m+1)
        {
            cin>>dum;

            if(dum == '.')
            {
                cnt++;
            }
            else
            {
                res += dp[cnt];
                cnt = 0;
            }
        }

        if(cnt)res += dp[cnt];
    }

    cout << res << endl;
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

    cin >> t;   

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}