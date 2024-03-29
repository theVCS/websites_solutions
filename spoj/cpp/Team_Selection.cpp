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

#define maxN 500001
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

int n;

struct contest
{
    int rank1, rank2, rank3;
}arr[maxN];


template <class T>
class FenwickTree
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, INF);
    }

    T query(int index)
    {
        T q = INF;

        while (index > 0)
        {
            q = min(q,BIT[index]);
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] = min(BIT[index],val);
            index += (index & -index);
        }
    }
};

bool cmp(contest &a, contest &b)
{
    return a.rank1 < b.rank1;
}

void solve()
{
    cin>>n;

    FenwickTree<int>ft(n);

    REP(i,1,n)
    {
        int pos;
        cin>>pos;
        arr[pos].rank1=i;
    }

    REP(i,1,n)
    {
        int pos;
        cin>>pos;
        arr[pos].rank2=i;
    }

    REP(i,1,n)
    {
        int pos;
        cin>>pos;
        arr[pos].rank3=i;
    }

    sort(arr+1,arr+1+n,cmp);

    int ans = 0;

    REP(i,1,n)
    {
        int mn = ft.query(arr[i].rank2-1);
        if(mn>arr[i].rank3)ans++;
        ft.update(arr[i].rank2, arr[i].rank3);
    }

    cout<<ans;
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