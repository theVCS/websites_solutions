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

ll n, x;
ll arr[20];
int dp[(1<<20)];

int fun(int mask = 0)
{
    if (mask == ((1 << n) - 1))
        return 0;
    else if(dp[mask] != -1)
        return dp[mask];

    vector<int> vec;

    REP(i, 0, n - 1)
    {
        if (((1 << i) & mask) == 0)
        {
            vec.push_back(i);
        }
    }

    int sz = vec.size();
    int res = INF;

    REP(bit_mas, 1, (1 << sz) - 1)
    {
        int temp = mask;
        ll sum = 0;

        REP(i, 0, sz - 1)
        {
            if ((1 << i) & bit_mas)
            {
                sum += arr[vec[i]];
                temp |= (1 << vec[i]);
            }
        }

        if (sum <= x)
        {
            res = min(res, 1 + fun(temp));
        }
    }

    return dp[mask] = res;
}

void solve()
{
    cin >> n >> x;

    REP(i, 0, n - 1)
    cin >> arr[i];

    memset(dp,-1,sizeof(dp));

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