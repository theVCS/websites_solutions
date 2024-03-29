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
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        power >>= 1;
    }
    return res;
}

int n;

struct veg
{
    int w, x, y, z;
} arr[maxN];

template <class T>
class FenwickTree2D
{
    ll n, m;
    ll pos;
    ll BIT[200000000];
    // 200000000

public:
    FenwickTree2D(int N, int M)
    {
        REP(i,0,200000000-1)BIT[i]=INF;
        n = N;
        m = M;
        pos = 0;
    }

    T _query_(ll x, ll y)
    {
        T q = INF;

        while (y > 0)
        {
            ll en = ((x * 0x1f1f1f1f) ^ y) % 199999999 + 1;
            q = min(q, BIT[en]);
            y -= (y & -y);
        }

        return q;
    }

    T query(int x, int y)
    {
        T q = INF;

        while (x > 0)
        {
            q = min(q, _query_(x, y));
            x -= (x & -x);
        }

        return q;
    }

    void __update__(ll x, ll y, T v)
    {
        while (y <= m)
        {
            ll en = ((x * 0x1f1f1f1f) ^ y) % 199999999 + 1;
            BIT[en] = min(BIT[en], v);
            y += (y & -y);
        }
    }

    void update(int x, int y, T val)
    {
        while (x <= n)
        {
            __update__(x, y, val);
            x += (x & -x);
        }
    }
};

bool cmp(veg a, veg b)
{
    return a.w < b.w;
}

void solve()
{
    cin >> n;
    FenwickTree2D<ll> ft(n, n);

    REP(i, 1, n)
    cin >> arr[i].w >> arr[i].x >> arr[i].y >> arr[i].z;

    sort(arr + 1, arr + 1 + n, cmp);

    int ans = 0;

    REP(i, 1, n)
    {
        int q = ft.query(arr[i].x, arr[i].y);
        if (arr[i].z < q)
            ans++;
        ft.update(arr[i].x, arr[i].y, arr[i].z);
    }

    cout << ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("inputD.txt","r",stdin);
    // freopen("a.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}