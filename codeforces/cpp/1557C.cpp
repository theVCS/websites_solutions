#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 200001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}

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

int n, k;
ll dp[maxN];
ll p;

// even
ll fun1(int k)
{
    if (k == 0)
    {
        return dp[k] = 1;
    }
    else if(dp[k]!=-1)
        return dp[k];
    else
    {
        return dp[k] = (binExp(binExp(2, k - 1), n) + (p * fun1(k - 1)) % mod) % mod;
    }
}

ll fun2(int k)
{
    if (k == 0)
    {
        return dp[k] = 1;
    }
    else if(dp[k]!=-1)
        return dp[k];
    else
    {
        return dp[k] = (fun2(k - 1) + (p * fun2(k - 1)) % mod) % mod;
    }
}

void solve()
{
    cin >> n >> k;
    p = binExp(2, n - 1);
    if(n%2==0)p-=1;
    memset(dp,-1,sizeof(dp));
    // cout<<fun(k)<<endl;

    if (n % 2)
    {
        cout << fun2(k) << endl;
    }
    else
    {
        cout << fun1(k) << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("inputD.txt","r",stdin);
    // freopen("a.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}