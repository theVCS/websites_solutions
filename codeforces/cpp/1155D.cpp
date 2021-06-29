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
#define maxN 300001
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

int n, x;
ll arr[maxN];
ll dp[maxN][3][2];

// kind = 0 means not used yet
// kind = 1 means used in past and still can be used
// kind = 2 now x is not usable

// type = 0 tell that elements are not picked yet for sum
// type = 1 tells elements have been picked up in continuous manner

ll fun(int index, int kind, int type)
{
    if (index == n + 1)
    {
        return 0;
    }
    else if (dp[index][kind][type] != -1)
    {
        return dp[index][kind][type];
    }
    else
    {
        if (kind == 2)
        {
            return dp[index][kind][type] = max(0LL, arr[index] + fun(index + 1, 2, 1));
        }
        else if (kind == 1)
        {
            return dp[index][kind][type] = max({x * arr[index] + fun(index + 1, 1, 1), arr[index] + fun(index + 1, 2, 1), 0LL});
        }
        else
        {
            if (type)
            {
                return dp[index][kind][type] = max({arr[index] * x + fun(index + 1, 1, 1), arr[index] + fun(index + 1, 0, 1), 0LL});
            }
            else
            {
                return dp[index][kind][type] = max({fun(index + 1, 0, 0), arr[index] + fun(index + 1, 0, 1), arr[index] * x + fun(index + 1, 1, 1)});
            }
        }
    }
}

void solve()
{
    cin >> n >> x;

    REP(i, 1, n)
    {
        cin >> arr[i];

        dp[i][0][0] = dp[i][1][0] = dp[i][2][0] = -1;
        dp[i][0][1] = dp[i][1][1] = dp[i][2][1] = -1;
    }

    cout << fun(1,0,0);
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