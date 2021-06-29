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
#define maxN 5001
#define endl "\n"
#define INF 10000000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n;
ll arr[maxN];

ll fun(int l, int r, ll pmn = 0)
{
    if (l > r)
        return 0;

    ll mn = INF;
    vector<int> ind;

    REP(i, l, r)
    {
        if (mn > arr[i])
        {
            ind.clear();
            mn = arr[i];
            ind.push_back(i);
        }
        else if (arr[i] == mn)
        {
            ind.push_back(i);
        }
    }

    int _l = l;
    ll ans = mn - pmn;

    for (int in : ind)
    {
        ans += fun(_l, in-1, mn);
        _l = in + 1;
    }

    ans += fun(_l, r, mn);
    return min((r - l + 1) * 1LL, ans);
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i];

    cout << fun(1, n);
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