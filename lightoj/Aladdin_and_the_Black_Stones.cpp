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

#define maxN 501
#define INF 1000000000
#define mod 4294967296
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
int arr[maxN];

struct element
{
    int sum, x, y;

    element(int _sum, int _x, int _y)
    {
        sum = _sum;
        x = _x;
        y = _y;
    }
};

vector<element> vec;

bool cmp(element &a, element &b)
{
    if (a.sum != b.sum)
        return a.sum < b.sum;
    else if (a.x != b.x)
        return a.x<b.x;
    else
        return a.y>b.y;
}

template <class T>
class FenwickTree2D
{
    int n, m;
    vector<vector<T>> BIT;

public:
    FenwickTree2D(int N, int M)
    {
        n = N;
        m = M;
        BIT.resize(n + 1);

        for (vector<T> &vec : BIT)
            vec.assign(m + 1, 0);
    }

    T __query__(int x, int y)
    {
        T sum = 0;

        while (y > 0)
        {
            sum += BIT[x][y];
            y -= (y & -y);
        }

        return sum;
    }

    T _query_(int x, int y)
    {
        T sum = 0;

        while (x > 0)
        {
            sum += __query__(x, y);
            x -= (x & -x);
        }

        return sum;
    }

    T query(int x2, int y2, int x1, int y1)
    {
        return _query_(x2, y2) - _query_(x1 - 1, y2) - _query_(x2, y1 - 1) + _query_(x1 - 1, y1 - 1);
    }

    void __update__(int x, int y, T val)
    {
        while (y <= m)
        {
            BIT[x][y] += val;
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


void solve()
{
    vec.clear();

    cin >> n;

    REP(i, 1, n)
    cin >> arr[i];

    REP(i, 1, n)
    REP(j, i + 1, n)
    vec.push_back(element(arr[i] + arr[j], i, j));

    sort(all(vec), cmp);

    FenwickTree2D<ll>ft(n,n);

    ll ans = 0;

    for(element e: vec)
    {
        // cout<<e.sum<<" "<<e.x<<" "<<e.y<<endl;
        ll res = (ft.query(n, e.y-1, e.x+1, 1)+1)%mod;
        ans = (ans+res)%mod;
        ft.update(e.x,e.y,res);
    }

    cout<<ans<<endl;
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
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
}