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
#define maxN 200001
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

int n;
ll t, arr[maxN];
vector<ll> segTree[4 * maxN];

int bs(vector<ll> &vec, ll ele)
{
    int start = 0, end = vec.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (vec[mid] > ele && (mid == start || vec[mid - 1] <= ele))
            return vec.size() - mid;
        else if (vec[mid] <= ele)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0;
}

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back(arr[ss]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        merge(all(segTree[2 * si]), all(segTree[2 * si + 1]), back_inserter(segTree[si]));
    }
}

ll query(int si, int ss, int se, int qs, int qe, ll ele)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return bs(segTree[si], ele);
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe, ele) + query(2 * si + 1, mid + 1, se, qs, qe, ele));
}

void solve()
{
    cin >> n >> t;

    REP(i, 1, n)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    build(1, 1, n);

    ll ans = 0;

    REP(i, 1, n)
    {
        ll ele = arr[i] - t;
        ans += query(1, 1, n, 1, i - 1, ele);

        if (arr[i] < t)
            ans++;
    }

    cout << ans;
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