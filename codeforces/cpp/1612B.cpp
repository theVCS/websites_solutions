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

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    bool use[n + 1] = {false};
    int arr[n + 1];

    arr[n / 2] = a;
    use[a] = true;

    arr[n/2 + 1] = b;
    use[b]=true;

    int ptr = n;

    REP(i, 1, n / 2 - 1)
    {
        while (use[ptr] == true)
            ptr--;
        arr[i] = ptr, use[ptr] = true;
    }

    ptr = 1;

    REP(i,n/2+2,n)
    {
        while(use[ptr]==true)ptr++;
        arr[i]=ptr, use[ptr]=true;
    }

    int mn = INF;

    REP(i,1,n/2)
    {
        mn = min(mn, arr[i]);
    }

    if(mn!=a)
    {
        cout<<-1<<endl;
        return;
    }

    int mx = -INF;

    REP(i,n/2+1,n)mx=max(mx,arr[i]);

    if(mx!=b)
    {
        cout<<-1<<endl;
        return;
    }

    REP(i,1,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}