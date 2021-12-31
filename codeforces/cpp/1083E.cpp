#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct Line
{
    mutable ll m, b, p;
    bool operator<(const Line &o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

// for maximum value
struct LineContainer : multiset<Line, less<>>
{
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    
    ll div(ll a, ll b)
    { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y)
    {
        if (y == end())
        {
            x->p = inf;
            return false;
        }
        if (x->m == y->m)
            x->p = x->b > y->b ? inf : -inf;
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }
    
    void add(ll m, ll b)
    {
        auto z = insert({m, b, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    ll query(ll x)
    {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.b;
    }
} cht;

struct rectangle
{
    ll x,y,a;
}arr[maxN];

bool cmp(rectangle &a, rectangle &b)
{
    return a.x<b.x;
}

void solve()
{
    int n;
    cin>>n;

    REP(i,1,n)
    cin>>arr[i].x>>arr[i].y>>arr[i].a;

    sort(arr+1,arr+1+n,cmp);

    ll dp = arr[1].x*arr[1].y - arr[1].a;
    cht.add(-arr[1].x,dp);

    REP(i,2,n)
    {
        ll res=max(0LL,cht.query(arr[i].y)) + arr[i].x*arr[i].y-arr[i].a;
        dp=max(dp,res);
        cht.add(-arr[i].x,dp);
    }

    cout<<dp<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}