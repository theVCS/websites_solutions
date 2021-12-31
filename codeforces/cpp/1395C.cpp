/************************/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

/************************/

#include <bits/stdc++.h>
#define M 1000000007
#define ll long long int
#define INF 1e18
#define pi pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define vll vector<long long int>
#define vpair vector<pair<ll, ll>>
#define w(t)      \
    ll tests;     \
    cin >> tests; \
    while (tests--)
#define endl "\n"
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define rep1(i, a, b) for (ll i = a; i < b; i++)
#define rep2(j, a, b) for (ll j = a; j >= b; j--)

using namespace std;
using namespace chrono;

/************************/

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/************************/

// ll power(ll a, ll b)
// {
//     if (b == 0)
//         return 1;
//     ll x = power(a, b / 2);
//     x = x * x;
//     if (b % 2 == 1)
//     {
//         x *= a;
//     }
//     return x;
// }

// ll mod_add(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mod_mul(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll mod_sub(ll a, ll b, ll m)
// {
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }

// bool prime[100000000 + 1];
// void sieve()
// {
//     ll n = 100000000 + 1;
//     for (ll p = 2; p * p <= n; p++)
//     {
//         if (prime[p] == true)
//         {
//             for (ll i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
//     prime[1] = false;
//     prime[0] = false;
// }

/*********************/

// ll intlog(double base, double x)
// {
//     return (ll)(log(x) / log(base));
// }

// /********LCS***********/

// ll lcs(string s1, string s2)
// {
//     ll n1 = s1.size();
//     ll n2 = s2.size();
//     ll dp[n1 + 1][n2 + 1];
//     memset(dp, -1, sizeof(dp));
//     for (ll i = 0; i <= n1; i++)
//     {
//         for (ll j = 0; j <= n2; j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 dp[i][j] = 0;
//             }
//             else
//             {
//                 if (s1[i - 1] == s2[j - 1])
//                 {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }
//     }
//     return dp[n1][n2];
// }

// ll power(ll a, ll b)
// {
//     if (b == 0)
//     {
//         return 1;
//     }
//     ll x = power(a, b / 2);
//     ll ans = (x * x);
//     if (b % 2 == 1)
//     {
//         return (ans * a);
//     }
//     return ans ;
// }

/**************************/

//input

void ip(vll &arr)
{
    rep1(i, 0, arr.size())
    {
        cin >> arr[i];
    }
}

vll a, b;
ll n, m;
ll dp[201][1<<9];

ll minimum_or(ll idx, ll val=0)
{
    if (idx == n)
        return 0;
    else if(dp[idx][val]!=-1)
        return dp[idx][val];

    ll ans = (1 << 9);
    
    for (ll i = 0; i < m; i++)
    {
        ll c = (a[idx] & b[i]);
        ll x = minimum_or(idx + 1, val|c);
        ans = min(ans, (val | x | c));
    }

    return dp[idx][val] = ans;
}

void solve()
{
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    ip(a);
    ip(b);
    memset(dp,-1,sizeof(dp));
    cout << minimum_or(0) << endl;
}

int main()
{

    //Not during Kickstart

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    // sieve();
    // ll cnt = 1;
    auto start1 = high_resolution_clock::now();
    // w(t)
    {
        // cout << "Case #" << cnt << ": ";
        // cnt++;
        solve();
    }
    // auto stop1 = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop1 - start1);
    // cerr << "Time: " << duration.count() / 1000 << endl;
}