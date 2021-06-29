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
#define maxN 200001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
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

string s;
ll dp[maxN][2];

ll fun()
{
    int n = s.size();

    if (s[0] == '?')
    {
        dp[0][0] = 1;
        dp[0][1] = 1;
    }
    else if (s[0] == '0')
    {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    else
    {
        dp[0][0] = 0;
        dp[0][1] = 1;
    }

    REP(i, 1, n - 1)
    {
        if (s[i] == '?')
        {
            if (s[i - 1] == '0')
            {
                dp[i][0] = 1;
                dp[i][1] = 1 + dp[i - 1][0];
            }
            else if (s[i - 1] == '1')
            {
                dp[i][0] = 1 + dp[i - 1][1];
                dp[i][1] = 1;
            }
            else
            {
                dp[i][0] = 1 + dp[i - 1][1];
                dp[i][1] = 1 + dp[i - 1][0];
            }
        }
        else if (s[i] == '0')
        {
            // if (s[i - 1] == '?')
            // {
            //     dp[i][0] = dp[i - 1][1];
            //     dp[i][1] = 0;
            // }
            // else
            // {
                dp[i][0] = 1 + dp[i - 1][1];
            // }
            dp[i][1] = 0;
        }
        else
        {
            // if (s[i - 1] == '?')
            // {
            //     dp[i][1] = dp[i - 1][0];
            // }
            // else
            // {
                dp[i][1] = 1 + dp[i - 1][0];
            // }
            dp[i][0] = 0;
        }
    }

    REP(i, 0, n - 1)
    cout << dp[i][0] << " ";
    cout << endl;
    REP(i, 0, n - 1)
    cout << dp[i][1] << " ";
    cout << endl;
    cout << endl;
}

void solve()
{
    cin >> s;
    int arr[] = {-1,-1};
    
    int n = s.size();
    ll ans = 0;

    REP(i,0,n-1)
    {
        int c = s[i] - '0';
        if(c == 0 || c == 1)
        {
            arr[(i%2)^(c)] = i;
        }

        int mn = min(arr[0],arr[1]);
        ans += i - mn;
    }

    cout<<ans<<endl;
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