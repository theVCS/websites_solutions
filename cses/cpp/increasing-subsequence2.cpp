#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define INF 1000000000
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int n;
int arr[maxN];
map<int, int> mp;

int segTree[4 * maxN];

int query(int si, int ss, int se, int qs, int qe)
{
    // cout << ss << " " << se << endl;

    if (qs > se || qe < ss)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se)/2;
    return max(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qi, int val)
{
    if (ss == se)
    {
        segTree[si] = max(segTree[si], val);
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi, val);
    else
        update(2 * si + 1, mid + 1, se, qi, val);

    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

void solve()
{
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
    {
        arr[i] = mp[arr[i]];
    }

    int res = 0;

    REP(i, 1, n + 1)
    {
        int pres = 1 + query(1, 1, timer, 1, arr[i] - 1);
        update(1, 1, timer, arr[i], pres);
        res = max(res, pres);
        // cout << pres << endl;
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}