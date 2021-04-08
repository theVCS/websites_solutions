//*******************************************************************
//              author of this code is : horcrux903
//*******************************************************************
//        THERE IS ALWAYS A WAY TO GO IF YOU LOOK FOR IT
//*******************************************************************

//*******************************************************************

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define ull unsigned long long int
#define ld long double
#define F(i, a, n) for (long long int i = a; i < n; i++)
#define FO(i, a, n) for (long long int i = n - 1; i >= a; i--)
#define fast()               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define pb(i) push_back(i)
#define len(s) s.length()
#define mp make_pair
#define PI 3.141592653589793238462643383279
#define ss second
#define ff first
#define vll vector<long long int>
#define vpair vector<pair<long long int, long long int>>
// const int inf = 1e18L + 5;

using namespace std;

// using namespace __gnu_pbds;
// template <typename T>
// using ordered_Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//*******************************************************************

long long int M = 1e9 + 7;

void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//********************************************************************

// ll gcd(ll a, ll b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// ll lcm(ll a, ll b)
// {
//     return (a * b) / gcd(a, b);
// }

//********************************************************************

// ll power(ll x, ll y, ll mod)
// {
//     ll res = 1;

//     x = x % mod;

//     while (y > 0)
//     {
//         if (y & 1)
//             res = ((res % mod) * (x % mod)) % mod;

//         y = y >> 1;
//         x = ((x % mod) * (x % mod)) % mod;
//     }
//     return res;
// }

//********************************************************************

// ll f[200006];

// ll ncr(ll n, ll r)
// {
//     if (n < r)
//     {
//         return 0;
//     }
//     ll num = f[n];
//     ll temp = (f[r] * (f[n - r])) % M;
//     ll ans = num * power(temp, M - 2);
//     return (ans % M);
// }

//********************************************************************

// ll bs(vll &arr, ll target, ll end)
// {
//     ll start = 0;

//     ll ans = -1;

//     while (start <= end)
//     {
//         ll mid = (start + end) / 2;

//         if (arr[mid] <= target)
//             start = mid + 1;

//         else
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//     }
//     return ans;
// }

//*******************************************************************

// bool prime[1000006];
// vll v;

// void SieveOfEratosthenes(int n)
// {
//     memset(prime, true, sizeof(prime));

//     prime[0] = prime[1] = false;

//     for (int p = 2; p * p <= n; p++)
//     {
//         if (prime[p] == true)
//         {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }

//     for (int p = 2; p <= n; p++)
//         if (prime[p])
//             v.pb(p);
// }

//*******************************************************************

ll n, d;
ll a[100005];
vector<ll> vec;

int dp[100005][15];

vector<vector<ll>> v;

bool ans(ll i = 0, ll j = 11)
{
    // cout << j << endl;
    if (i == n)
    {
        if (j == d)
        {
            v.push_back(vec);
            return true;
        }
        return false;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    vec.push_back(a[i]);
    bool res1 = ans(i + 1, (a[i] * (j % 10)) % 10);
    vec.pop_back();

    bool res2 = ans(i + 1, j);
    return dp[i][j] = res1 || res2;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> d;

    F(i, 0, n)
    {
        cin >> a[i];
    }

    // sort(a, a + n, greater<int>());

    int res = ans();
    
    F(i,0,n)
    {
       F(j,0,12)
       cout<<dp[i][j]<<" ";
       cout<<endl; 
    }

    if (res == false)
    {
        cout << -1;
        return;
    }
    else
    {
        ll sum = 0;

        for (auto x : v)
        {
            ll temp = 0;

            for (auto y : x)
            {
                temp += y;
            }
            sum = max(sum, temp);
        }

        for (auto x : v)
        {
            ll temp = 0;

            for (auto y : x)
            {
                temp += y;
            }
            if (temp == sum)
            {
                cout << x.size() << endl;

                for (auto y : x)
                {
                    cout << y << " ";
                }
                break;
            }
        }
    }
}

//*******************************************************************

int main()
{
    fast()
        // input();

        // SieveOfEratosthenes(1000006);

        // f[0] = 1;

        // F(i, 1, 2e5 + 1)
        // {
        //     f[i] = (f[i - 1] * i) % M;
        // }

        int t = 1,
            i = 1;
    // cin >> t;

    while (t--)
    {
        // cout << "Case #" << i << ": ";      //only during google contest
        // i++;                                //only during google contest
        solve();
        cout << endl;
    }
}