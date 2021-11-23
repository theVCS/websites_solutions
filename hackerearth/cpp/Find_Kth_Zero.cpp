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

#define maxN 100001
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

int n, m;
ll arr[maxN];

template <class T>
class SegmentTree
{
    int n;
    vector<T> segTree;

public:
    SegmentTree(int N)
    {
        n = N;
        segTree.resize(4 * n);
    }

    void _build_(int si, int ss, int se, T arr[])
    {
        if (ss == se)
        {
            segTree[si] = !arr[ss];
        }
        else
        {
            int mid = (ss + se) / 2;
            _build_(2 * si, ss, mid, arr);
            _build_(2 * si + 1, mid + 1, se, arr);
            segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
        }
    }

    void build(T arr[])
    {
        _build_(1, 1, n, arr);
    }

    T _query_(int si, int ss, int se, int qs, int qe)
    {
        if (qs > se || qe < ss)
            return 0;
        if (qs <= ss && qe >= se)
            return segTree[si];
        int mid = (ss + se) / 2;
        return _query_(2 * si, ss, mid, qs, qe) + _query_(2 * si + 1, mid + 1, se, qs, qe);
    }

    T _query_(int si, int ss, int se, int qi)
    {
        if (ss == se)
            return ss;
        else
        {
            int mid = (ss + se) / 2;
            if (qi <= segTree[2*si])
                return _query_(2 * si, ss, mid, qi);
            else
                return _query_(2 * si + 1, mid + 1, se, qi-segTree[2*si]);
        }
    }

    T query(int l, int r)
    {
        return _query_(1, 1, n, l, r);
    }

    T query(int qi)
    {
        return _query_(1, 1, n, qi);
    }

    void _update_(int si, int ss, int se, int qi, T val)
    {
        if (ss == se)
        {
            segTree[si] = !val;
        }
        else
        {
            int mid = (ss + se) / 2;
            if (qi <= mid)
                _update_(2 * si, ss, mid, qi, val);
            else
                _update_(2 * si + 1, mid + 1, se, qi, val);
            segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
        }
    }

    void update(int qi, T val)
    {
        _update_(1, 1, n, qi, val);
    }
};


void solve()
{
    cin>>n>>m;
    REP(i,1,n)cin>>arr[i];
    SegmentTree<ll>segTree(n);
    segTree.build(arr);

    while (m--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int k;
            cin>>k;
            if(segTree.query(1,n)<k)cout<<"NO"<<endl;
            else cout<<segTree.query(k)-1<<endl;
        }
        else
        {
            int p, x;
            cin>>p>>x;
            p++;
            segTree.update(p,x);
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