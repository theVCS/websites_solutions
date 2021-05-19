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
#define maxN 1000001
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

int n, m;
string s[16];
int dp[16][2];

int fun(int floor = 1, int left = 1)
{
    if (dp[floor][left] != -1)
        return dp[floor][left];
    else if (floor == n)
    {
        if (left)
        {
            int index = 0;
            RREP(i, m, 1)
            {
                if (s[floor][i] == '1')
                {
                    index = i;
                    break;
                }
            }

            return dp[floor][left] = index;
        }
        else
        {
            int index = m + 1;
            REP(i, 1, m)
            {
                if (s[floor][i] == '1')
                {
                    index = i;
                    break;
                }
            }

            return dp[floor][left] = (m + 1 - index);
        }
    }
    else if (left)
    {
        int index = 0;
        RREP(i, m, 1)
        {
            if (s[floor][i] == '1')
            {
                index = i;
                break;
            }
        }

        return dp[floor][left] = min(2 * index + 1 + fun(floor + 1, 1), m + 2 + fun(floor + 1, 0));
    }
    else
    {
        int index = m + 1;
        REP(i, 1, m)
        {
            if (s[floor][i] == '1')
            {
                index = i;
                break;
            }
        }

        return dp[floor][left] = min(2 * (m + 1 - index) + 1 + fun(floor + 1, 0), m + 2 + fun(floor + 1, 1));
    }
}

void solve()
{
    cin >> n >> m;

    RREP(i, n, 1)
    cin >> s[i];

    RREP(i, n, 1)
    {
        bool flag = false;

        for(char c: s[i])
        {
            if(c == '1')
            {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            n = i;
            break;
        }

        if(i == 1 && flag == false)
        {
            cout<<0;
            return;
        }
    }

    // cout<<n<<endl;

    memset(dp, -1, sizeof(dp));

    cout << fun();
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