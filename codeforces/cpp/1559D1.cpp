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

class DSU
{
    int n;
    vector<int> par;

public:
    DSU(int N)
    {
        n = N;
        par.assign(n + 1, -1);
    }

    int find(int a)
    {
        if (par[a] < 0)
            return a;
        else
            return par[a] = find(par[a]);
    }

    void merger(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(a==b)return;

        if (par[a] > par[b])
            swap(a, b);

        par[a] += par[b];
        par[b] = a;
    }
};

int n;
int m1, m2;

void solve()
{
    cin >> n >> m1 >> m2;
    DSU dsu1(n), dsu2(n);

    REP(i, 1, m1)
    {
        int a, b;
        cin>>a>>b;
        dsu1.merger(a,b);
    }

    REP(i, 1, m2)
    {
        int a, b;
        cin>>a>>b;
        dsu2.merger(a,b);
    }

    vector<pii>res;

    REP(a,1,n)
    {
        REP(b,a+1,n)
        {
            int pa = dsu1.find(a);
            int pb = dsu1.find(b);

            if(pa==pb)continue;
        
            pa = dsu2.find(a);
            pb = dsu2.find(b);

            if(pa==pb)continue;

            dsu1.merger(a,b);
            dsu2.merger(a,b);

            res.push_back({a,b});
        }
    }

    cout<<res.size()<<endl;

    for(pii e: res)
    cout<<e.first<<" "<<e.second<<endl;
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