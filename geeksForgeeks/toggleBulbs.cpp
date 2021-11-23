#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

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
            res = mulmod(res,a,m);
        a = mulmod(a,a,m);
        power >>= 1;
    }
    return res;
}

template <class T>
class SegmentTreeLazyPropogation
{
    int n;
    vector<T> segTree;
    vector<T> lazy;

public:
    SegmentTreeLazyPropogation(int N)
    {
        n = N;
        segTree.resize(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    T _query_(int si, int ss, int se, int qs, int qe)
    {
        if (lazy[si])
        {
            segTree[si] = (se - ss + 1) - segTree[si];

            if (ss != se)
            {
                lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];
                lazy[2*si] %= 2,  lazy[2*si+1] %= 2;
            }

            lazy[si] = 0;
        }

        if (qs > se || qe < ss)
            return 0;

        if (qs <= ss && qe >= se)
            return segTree[si];

        int mid = (ss + se) / 2;
        return _query_(2 * si, ss, mid, qs, qe) + _query_(2 * si + 1, mid + 1, se, qs, qe);
    }

    T query(int l, int r=-1)
    {
        if(r==-1)r=l;
        return _query_(1, 1, n, l, r);
    }

    void _update_(int si, int ss, int se, int qs, int qe, T val)
    {
        if (lazy[si])
        {
            segTree[si] = (se - ss + 1) - segTree[si];

            if (ss != se)
            {
                lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];
                lazy[2*si] %= 2,  lazy[2*si+1]%=2;
            }

            lazy[si] = 0;
        }

        if (ss > qe || se < qs)
            return;

        if (qs <= ss && qe >= se)
        {
            segTree[si] = (se - ss + 1) - segTree[si];

            if (ss != se)
            {
                lazy[2 * si] += val, lazy[2 * si + 1] += val;
                lazy[2*si] %= 2, lazy[2*si+1] %= 2;
            }

            return;
        }

        int mid = (ss + se) / 2;

        _update_(2 * si, ss, mid, qs, qe, val);
        _update_(2 * si + 1, mid + 1, se, qs, qe, val);

        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }

    void update(int l, int r, T val)
    {
        _update_(1, 1, n, l, r, val);
    }
};

int n, q;

void solve()
{
    cin>>n>>q;
    SegmentTreeLazyPropogation<int>segTree(n);

    while (q--)
    {
        int type, a, b;
        cin>>type>>a>>b;
        // a++,b++;

        if(type==1)
        {
            segTree.update(a,b,1);
        }
        else
        {
            cout<<segTree.query(a,b)<<endl;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("inputD.txt","r",stdin);
    //freopen("a.txt","w",stdout);

    int t = 1;

    //cin >> t;

    REP(tc,1,t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}