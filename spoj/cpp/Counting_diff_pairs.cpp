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

#define maxN 50001
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

template <class T>
class FenwickTree
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree() {}

    FenwickTree(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    void resize(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    T query(int index)
    {
        T q = 0;

        while (index > 0)
        {
            q += BIT[index];
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] += val;
            index += (index & -index);
        }
    }

    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int lowerBound(T val)
    {
        // will find the lower bound index of val in BIT if monotonically increasing
        // https://codeforces.com/blog/entry/61364

        T q = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= n && q + BIT[pos + (1 << i)] < val)
            {
                q += BIT[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};

template <class T>
class FenwickTree1
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree1() {}

    FenwickTree1(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    void resize(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    T query(int index)
    {
        T q = 0;

        while (index <= n)
        {
            q += BIT[index];
            index += (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index > 0)
        {
            BIT[index] += val;
            index -= (index & -index);
        }
    }

    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int lowerBound(T val)
    {
        // will find the lower bound index of val in BIT if monotonically increasing
        // https://codeforces.com/blog/entry/61364

        T q = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= n && q + BIT[pos + (1 << i)] < val)
            {
                q += BIT[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};

int arr[maxN], k;

template <class T>
class MO
{
    struct Query
    {
        int l, r, index;
        ll order;

        Query(int _l, int _r, int _index)
        {
            l = _l;
            r = _r;
            index = _index;
            order = gilbertOrder(l, r, 21, 0);
        }

        inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
        {
            if (pow == 0)
            {
                return 0;
            }
            int hpow = 1 << (pow - 1);
            int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
            seg = (seg + rotate) & 3;
            const int rotateDelta[4] = {3, 0, 0, 1};
            int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
            int nrot = (rotate + rotateDelta[seg]) & 3;
            int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
            int64_t ans = seg * subSquareSize;
            int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
            ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
            return ans;
        }
    };

    int n, q;
    ll res;
    vector<ll> ans;
    vector<Query> Q;
    FenwickTree<int>ftb;
    FenwickTree1<int>ftf;

public:
    MO() {}

    // N -> no of elements, Q -> no of queries, R -> range of elements
    MO(int N, int Q, int R)
    {
        n = N;
        q = Q;
        res = 0;
        ans.resize(Q + 1);
        ftb.resize(100000);
        ftf.resize(100000);
    }

    void addQuery(int l, int r, int index)
    {
        Q.push_back(Query(l, r, index));
    }

    void add(int index)
    {
        ll ele = arr[index];
        res += ftf.query(k+ele);
        res += ftb.query(ele-k);
        ftf.update(ele,1);
        ftb.update(ele,1);
    }

    void remove(int index)
    {
        ll ele = arr[index];
        ftf.update(ele,-1);
        ftb.update(ele,-1);
        res -= ftf.query(k+ele);
        res -= ftb.query(ele-k);
    }

    void processQuery()
    {
        sort(all(Q), [](const Query &lhs, const Query &rhs)
             { return lhs.order < rhs.order; });

        for (int i = 0, L = 1, R = 0; i < q; i++)
        {
            while (R < Q[i].r)
                add(++R);
            while (L > Q[i].l)
                add(--L);
            while (R > Q[i].r)
                remove(R--);
            while (L < Q[i].l)
                remove(L++);

            ans[Q[i].index] = res;
        }
    }

    void showAns()
    {
        REP(i, 1, q)
        {
            cout << ans[i] << endl;
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m >> k;

    REP(i, 1, n)
    cin >> arr[i];

    MO<int> mo(n, m, 100000);

    REP(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        mo.addQuery(a, b, i);
    }

    mo.processQuery();
    mo.showAns();
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