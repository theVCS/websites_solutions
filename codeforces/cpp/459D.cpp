#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
vector<int> segTree[4 * maxN];

int prefix[maxN];
int suffix[maxN];
int temp[maxN];
map<int, int> mp;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back(suffix[ss]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        merge(all(segTree[2 * si]), all(segTree[2 * si + 1]), back_inserter(segTree[si]));
    }
}

int query(int si, int ss, int se, int qs, int qe, int val)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return lower_bound(all(segTree[si]), val) - segTree[si].begin();
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe, val) + query(2 * si + 1, mid + 1, se, qs, qe, val));
}

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        mp[arr[i]];
    }

    int timer = 0;

    for (auto &e : mp)
    {
        e.second = ++timer;
    }

    REP(i, 1, n + 1)
    arr[i] = mp[arr[i]];

    REP(i, 1, n + 1)
    {
        prefix[i] = ++temp[arr[i]];
    }

    memset(temp, 0, sizeof(temp));

    for (int i = n; i >= 1; i--)
    {
        suffix[i] = ++temp[arr[i]];
    }

    build(1, 1, n);

    ll res = 0;

    REP(i, 2, n)
    {
        res += query(1, 1, n, i + 1, n, prefix[i]);
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