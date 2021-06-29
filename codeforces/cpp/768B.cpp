#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
// #define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a);
        a = (a * a);
        power >>= 1;
    }

    return res;
}

ll n;

ll cnt(ll n)
{
    ll k = log2l(n);
    return binExp(2, k + 1) - 1;
}

int isOne(ll ele, ll eleCnt, ll target)
{
    eleCnt /= 2;

    if (target <= eleCnt)
    {
        return isOne(ele / 2, eleCnt, target);
    }
    else if (target == eleCnt + 1)
    {
        return (ele % 2);
    }
    else
    {
        return isOne(ele / 2, eleCnt, target - eleCnt - 1);
    }
}

void solve()
{
    ll l, r;
    cin >> n >> l >> r;

    if(n == 0)
    {
        cout<<0;
        return;
    }

    ll x = cnt(n);

    // cout<<x<<endl;

    ll res = 0;

    for (ll i = l; i <= r; i++)
    {
        // cout << i << " -> " << isOne(n, x, i) << endl;
        res += isOne(n,x,i);
    }

    cout << res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}