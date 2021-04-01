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

ll binExp(ll a, ll pow = mod - 2)
{
    ll res = 1;

    while (pow)
    {
        if (pow & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;

        pow >>= 1;
    }

    return res;
}

int n, k;
int arr[maxN];
ll dp[maxN][maxN];
ll fact[maxN];

void init()
{
    fact[0] = fact[1] = 1;

    REP(i, 2, n + 1)
    fact[i] = (fact[i - 1] * i) % mod;
}

ll nPr(ll n, ll r)
{
    if (n < r)
        return 0;

    ll a = fact[n];
    ll b = binExp(fact[r]);

    return (a * b) % mod;
}
vector<int> ele, fre;

void solve()
{
    cin >> n >> k;

    init();

    REP(i, 1, n + 1)
    cin >> arr[i];

    sort(arr + 1, arr + 1 + n);

    REP(i, 1, n + 1)
    {
        if (i == 1 || arr[i] != ele.back())
        {
            ele.push_back(arr[i]);
            fre.push_back(1);
        }
        else
        {
            fre.back()++;
        }
    }

    ll tot_ways = nPr(n, k);
    n = fre.size();

    // appplying dp
    REP(i, 0, k + 1)
    dp[0][i] = nPr(fre[0], i);

    REP(i, 1, n)
    {
        REP(j, 0, k + 1)
        {
            REP(k, 0, min(fre[i], j) + 1)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * nPr(fre[i], k)) % mod;
            }
        }
    }


    ll fav_ways = dp[n - 1][k];
    ll ans = (fav_ways * binExp(tot_ways)) % mod;
    cout << fav_ways;

    // cout << ans;
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