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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int segTree[4 * maxN];
vector<ll> prefix;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return INT_MIN;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return max(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

map<pii, int> mp;

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i];

    build(1, 1, n);

    int m, x, y, _x, _y, period = 1;

    cin >> m >> x >> y;
    mp[{min(x, y), max(x, y)}] = 1;
    prefix.push_back(1LL * query(1, 1, n, min(x, y) + 1, max(x, y) + 1));

    _x = (x + 7) % (n - 1);
    _y = (y + 11) % n;

    ll res = 0;

    while (mp[{min(_x, _y), max(_x, _y)}] == 0)
    {
        period++;
        mp[{min(_x, _y), max(_x, _y)}] = period;
        prefix.push_back(1LL * query(1, 1, n, min(_x, _y) + 1, max(_x, _y) + 1));
        prefix[period - 1] += prefix[period - 2];

        _x = (_x + 7) % (n - 1);
        _y = (_y + 11) % n;
    }

    int start = mp[{min(_x, _y), max(_x, _y)}];

    if (m < start)
    {
        cout << prefix[m - 1];
        return;
    }

    if (start > 1)
    {
        res += prefix[start - 2];
        m -= start - 2;
    }

    ll len = prefix.size() - start + 1;
    ll cycles = m / len;
    res = cycles * (prefix[period] - prefix[start - 1]);
    int phase = m % len;
    if (phase)
        res += prefix[start + phase - 1] - prefix[start - 1];
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