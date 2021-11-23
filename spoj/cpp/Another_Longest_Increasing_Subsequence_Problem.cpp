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

#define maxN 100001
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
int arr[maxN][2];

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

    T _query_(int x, int y)
    {
        T sum = 0;

        for (int i = x; i > 0; i -= (i & -i))
        {
            for (int j = y; j > 0; j -= (j & -j))
            {
                sum += BIT[i][j]
            }
        }

        return sum;
    }

    T query(int x2, int y2, int x1, int y1)
    {
        return _query_(x2, y2) - _query_(x1 - 1, y2) - _query_(x2, y1 - 1) + _query_(x1 - 1, y1 - 1);
    }

    void update(int x, int y, T val)
    {
        for (int i = x; i <= n; i += (i & -i))
        {
            for (int j = y; j <= m; j += (j & -j))
            {
                BIT[i][j] += val;
            }
        }
    }
};

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i][0] >> arr[i][1];
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