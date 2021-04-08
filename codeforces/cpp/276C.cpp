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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, q, a, b;
ll arr[maxN];
ll segTree[4 * maxN];
ll lazy[4 * maxN];
vector<ll> fre;

void update(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        segTree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (qs > se || qe < ss)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] += (se - ss + 1);

        if (ss != se)
            lazy[2 * si] += 1, lazy[2 * si + 1] += 1;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);
    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

void build(int si, int ss, int se)
{
    if (lazy[si])
    {
        segTree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss == se)
    {
        fre.push_back(segTree[si]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
    }
}

void solve()
{
    cin >> n >> q;

    REP(i, 1, n + 1)
    cin >> arr[i];

    sort(arr + 1, arr + 1 + n, greater<int>());

    while (q--)
    {
        cin >> a >> b;
        update(1, 1, n, a, b);
    }

    build(1, 1, n);

    sort(all(fre), greater<int>());

    ll ans = 0;
    int index = 1;

    for (ll f : fre)
    {
        ans += f * arr[index++];
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