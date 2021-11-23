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

#define maxN 1000001
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
class SegmentTreeLazyPropogation
{
    int n;
    vector<pair<T, T>> segTree;
    vector<T> lazy;

public:
    SegmentTreeLazyPropogation(int N)
    {
        n = N;
        segTree.resize(4 * n);
        lazy.assign(4 * n, 0);
    }

    void _build_(int si, int ss, int se, T arr[])
    {
        if (ss == se)
        {
            segTree[si].first = arr[ss] * arr[ss];
            segTree[si].second = arr[ss];
        }
        else
        {
            int mid = (ss + se) / 2;
            _build_(2 * si, ss, mid, arr);
            _build_(2 * si + 1, mid + 1, se, arr);
            segTree[si].first = segTree[2 * si].first + segTree[2 * si + 1].first;
            segTree[si].second = segTree[2 * si].second + segTree[2 * si + 1].second;
        }
    }

    void build(T arr[])
    {
        _build_(1, 1, n, arr);
    }

    T _query_(int si, int ss, int se, int qs, int qe)
    {
        if (lazy[si])
        {
            segTree[si].first += (se - ss + 1) * lazy[si] * lazy[si] + 2 * lazy[si] * segTree[si].second;
            segTree[si].second += (se - ss + 1) * lazy[si];

            if (ss != se)
                lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

            lazy[si] = 0;
        }

        if (qs > se || qe < ss)
            return 0;

        if (qs <= ss && qe >= se)
            return segTree[si].first;

        int mid = (ss + se) / 2;
        return _query_(2 * si, ss, mid, qs, qe) + _query_(2 * si + 1, mid + 1, se, qs, qe);
    }

    T query(int l, int r = -1)
    {
        if (r == -1)
            r = l;
        return _query_(1, 1, n, l, r);
    }

    void _update_(int si, int ss, int se, int qs, int qe, T val)
    {
        if (lazy[si])
        {
            segTree[si].first += (se - ss + 1) * lazy[si] * lazy[si] + 2 * lazy[si] * segTree[si].second;
            segTree[si].second += (se - ss + 1) * lazy[si];

            if (ss != se)
                lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

            lazy[si] = 0;
        }

        if (ss > qe || se < qs)
            return;

        if (qs <= ss && qe >= se)
        {
            segTree[si].first += (se - ss + 1) * val * val + 2 * val * segTree[si].second;
            segTree[si].second += (se - ss + 1) * val;

            if (ss != se)
                lazy[2 * si] += val, lazy[2 * si + 1] += val;

            return;
        }

        int mid = (ss + se) / 2;

        _update_(2 * si, ss, mid, qs, qe, val);
        _update_(2 * si + 1, mid + 1, se, qs, qe, val);

        segTree[si].first = segTree[2 * si].first + segTree[2 * si + 1].first;
        segTree[si].second = segTree[2 * si].second + segTree[2 * si + 1].second;
    }

    void update(int l, int r, T val)
    {
        _update_(1, 1, n, l, r, val);
    }
};

int n, q;
ll arr[100001];

void solve()
{
    cin >> n;
    REP(i,1,n)cin>>arr[i];
    SegmentTreeLazyPropogation<ll> segTree(n);
    segTree.build(arr);

    cin >> q;

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        l++, r++;

        if (type == 0)
        {
            cout << segTree.query(l, r) << endl;
        }
        else
        {
            ll val;
            cin >> val;
            segTree.update(l, r, val);
        }
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

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}