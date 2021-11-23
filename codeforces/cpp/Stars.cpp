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

#define maxN 129
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

template <class T>
class FenwickTree3D
{
    int l, m, n;
    vector<vector<vector<T>>> BIT;

public:
    FenwickTree3D(int L, int M, int N)
    {
        l = L;
        m = M;
        n = N;

        BIT.resize(l + 1);

        REP(i, 0, l)
        {
            BIT[i].resize(m + 1);
            REP(j, 0, m)
            BIT[i][j].assign(n + 1, 0);
        }
    }

    T ___query___(int x, int y, int z)
    {
        T sum = 0;

        while (z > 0)
        {
            sum += BIT[x][y][z];
            z -= (z & -z);
        }

        return sum;
    }

    T __query__(int x, int y, int z)
    {
        T sum = 0;

        while (y > 0)
        {
            sum += ___query___(x, y, z);
            y -= (y & -y);
        }

        return sum;
    }

    T _query_(int x, int y, int z)
    {
        T sum = 0;

        while (x > 0)
        {
            sum += __query__(x, y, z);
            x -= (x & -x);
        }

        return sum;
    }

    T query(int x2, int y2, int z2, int x1, int y1, int z1)
    {
        return _query_(x2, y2, z2) - _query_(x1 - 1, y2, z2) - _query_(x2, y1 - 1, z2) - _query_(x2, y2, z1 - 1) - _query_(x1 - 1, y1 - 1, z1 - 1) + _query_(x1-1,y1-1,z2) + _query_(x1-1,y2,z1-1) + _query_(x2,y1-1,z1-1);
    }

    void __update__(int x, int y, int z, T val)
    {
        while (z <= n)
        {
            BIT[x][y][z] += val;
            z += (z & -z);
        }
    }

    void _update_(int x, int y, int z, T val)
    {
        while (y <= m)
        {
            __update__(x, y, z, val);
            y += (y & -y);
        }
    }

    void update(int x, int y, int z, T val)
    {
        while (x <= l)
        {
            _update_(x, y, z, val);
            x += (x & -x);
        }
    }
};

void solve()
{
    cin >> n;
    FenwickTree3D<ll> ft(n, n, n);

    while (true)
    {
        int m;
        cin >> m;

        if (m == 1)
        {
            ll x, y, z, k;
            cin >> x >> y >> z >> k;
            x++, y++, z++;
            ft.update(x, y, z, k);
        }
        else if (m == 2)
        {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x1++, y1++, z1++, x2++, y2++, z2++;
            cout << ft.query(x2, y2, z2, x1, y1, z1) << endl;
        }
        else
        {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("stars.in", "r", stdin);
    freopen("stars.out", "w", stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}