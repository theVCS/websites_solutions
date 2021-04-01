//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
//#include<chrono>
//#include<random>
constexpr auto INF = 9223372036854775807;
typedef long long int ll;
typedef unsigned long long int ull;

#define f(i, a, b) for (ll i = (ll)a; i < (ll)b; i += 1)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i -= 1)
#define endl '\n'
#define MaxN 100005
#define N (ll)998244353 // prime modulo value
#define all(x) x.begin(), x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;

pair<ll, ll> t[4 * MaxN];

void build(vector<ll> &arr, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].first = arr[tl];
        if (arr[tl] == 1)
        {
            t[v].second = tl;
        }
        else
            t[v].second = -1;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(arr, 2 * v, tl, tm);
        build(arr, 2 * v + 1, tm + 1, tr);
        t[v].first = t[2 * v].first + t[2 * v + 1].first;
        t[v].second = max(t[2 * v].second, t[2 * v + 1].second);
    }
}

ll query(ll v, ll tl, ll tr, ll k)
{
    if (tl == tr)
    {
        while (t[v] == t[v - 1])
            v--;
        return t[v].first;
    }
    // return t[v].second;
    ll tm = (tl + tr) / 2;
    if (t[2 * v].first < k)
    {
        return query(2 * v + 1, tm + 1, tr, k);
    }
    else
    {
        return query(2 * v, tl, tm, k);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        t[v].first = val;
        if (val == 1)
            t[v].second = pos;
        else
            t[v].second = -1;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v].first = t[2 * v].first + t[2 * v + 1].first;
        t[v].second = max(t[2 * v].second, t[2 * v + 1].second);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("inputD.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // __int128
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i += 1)
        cin >> arr[i];
    build(arr, 1, 0, n - 1);
    //for(ll i=0;i<5;i+=1)cout<<t[i].first<<" "<<t[i].second<<endl;
    for (ll i = 0; i < m; i += 1)
    {
        ll q;
        cin >> q;
        if (q == 1)
        {
            ll pos;
            cin >> pos;
            arr[pos] = 1 - arr[pos];
            update(1, 0, n - 1, pos, arr[pos]);
        }
        else
        {
            ll k;
            cin >> k;
            k += 1;
            cout << query(1, 0, n - 1, k) << endl;
        }
    }
    return 0;
}