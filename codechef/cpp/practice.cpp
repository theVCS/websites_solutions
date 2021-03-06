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
#define set0(a) memset(a, 0, sizeof(a))
#define set1(a) memset(a, -1, sizeof(a))
#define setf(a) memset(a, false, sizeof(a))
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define len(s) s.length()
#define precision 0.00000001
#define M 1000000007
#define mp make_pair
#define PI 3.141592653589793238462643383279
#define ss second
#define ff first
#define vll vector<long long int>
#define vpair vector<pair<long long int, long long int>>
#define vvpair vector<vector<pair<long long int, long long int>>>
const long long int INF = 1e18L + 5;

using namespace std;

// using namespace __gnu_pbds;
// template <typename T>
// using ordered_Set = tree<T, null_type, less<T>,
//       rb_tree_tag, tree_order_statistics_node_update>;

//*******************************************************************

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//********************************************************************

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ll lcm(ll a, ll b)
// {
//     return (a * b) / gcd(a, b);
// }

//********************************************************************

ll power(ll x, ll y, ll mod)
{
    ll ans = 1;

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            ans = ((ans % mod) * (x % mod)) % mod;

        y = y >> 1;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return ans;
}

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
//     ll ans = num * power(temp, M - 2, M);
//     return (ans % M);
// }

//********************************************************************

// ll bs(vll &arr, ll target, ll end)
// {
//     ll start = 0;

//     ll ans = -1;

//     while (start <= end)
//     {
//         ll mid = start + (end - start) / 2;

//         if (arr[mid] < target)
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

// bool prime[10000006];
// vll v, v1;

// void SieveOfEratosthenes(int n)
// {
//     memset(prime, true, sizeof(prime));

//     prime[0] = prime[1] = false;

//     for (int p = 2; p * p <= n; p ++)
//     {
//         if (prime[p] == true)
//         {
//             for (int i = p * p; i <= n; i += p)
//             {
//                 prime[i] = false;
//             }
//         }
//     }

//     for (int p = 2; p <= n; p++)
//         if (prime[p])
//         {
//             v.eb(p);
//             v1.eb(p);
//         }
// }

//*******************************************************************

vll v[100005];
bool vis[100005];

ll mdist, mnode;

void dfs(ll i, ll dist = 0)
{
    vis[i] = true;

    if (dist >= mdist)
    {
        mdist = dist;
        mnode = i;
    }

    for (auto x : v[i])
    {
        if (!vis[x])
        {
            dfs(x, dist + 1);
        }
    }
}

ll n, m;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int myrand(int mod = n)
{
    return (mt() % mod) + 1;
}

void solve()
{
    setf(vis);

    cin >> n >> m;

    F(i, 0, m)
    {
        ll x, y;
        cin >> x >> y;

        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);

    F(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cout << "-1";
            return;
        }
    }

    ll ans = 0, val = 1, dis = 0;

    F(i, 1, 1001)
    {
        setf(vis);
        int node = myrand();
        mnode = 0, mdist = 0;
        dfs(node);
        dfs(mnode);
        dis = max(dis, mdist);
    }

    mdist = dis;

    // while (val < mdist)
    // {
    //     val = val * 2;
    //     ans++;
    // }

    cout << ceil(log2(mdist));
}

//*******************************************************************

int main()
{

    fast()
        input(); //comment this during codejam/kickstart

    // SieveOfEratosthenes(10000006);

    // f[0] = 1;

    // F(i, 1, 2e5 + 1)
    // {
    //     f[i] = (f[i - 1] * i) % M;
    // }

    // F(i, 1, v1.size())
    // {
    //     v1[i] += v1[i - 1];
    // }

    int t = 1, i = 1;
    // cin >> t;

    while (t--)
    {
        // cout << "Case #" << i << ": ";      //only during google contest
        // i++;                                //only during google contest

        solve();
        cout << endl;
    }
}

//*******************************************************************
