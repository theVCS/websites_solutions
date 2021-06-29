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
#define maxN 100001
#define endl "\n"
#define INF 1000000000
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

ll n, k, a, b;
ll arr[maxN];

int bs1(ll ele)
{
    int start = 1, end = k;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= ele && (mid == start || arr[mid - 1] < ele))
            return mid;
        else if (arr[mid] >= ele)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int bs2(ll ele)
{
    int start = 1, end = k;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] <= ele && (mid == end || arr[mid + 1] > ele))
            return mid;
        else if (arr[mid] <= ele)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int prefix(ll l, ll r)
{
    l = bs1(l);
    r = bs2(r);

    if (l == -1 || r == -1)
        return 0;

    return (r - l + 1);
}

ll fun(ll l, ll r)
{
    // destroying whole base
    ll cnt = prefix(l, r);
    ll res1 = 0;

    if (cnt == 0)
        res1 = a;
    else
        res1 = b * cnt * (r - l + 1);

    ll res2 = __LONG_LONG_MAX__;
    // trying to destroy the base by dividing in two parts
    if ((r - l + 1) >= 2 && cnt)
    {
        ll mid = (l + r) / 2;
        res2 = fun(l, mid) + fun(mid + 1, r);
    }

    return min(res1, res2);
}

void solve()
{
    cin >> n >> k >> a >> b;

    REP(i, 1, k)
    {
        cin >> arr[i];
    }

    sort(arr+1,arr+1+k);

    cout << fun(1, (1LL << n));
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