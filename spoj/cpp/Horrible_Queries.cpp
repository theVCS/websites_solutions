#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll segTree[4 * maxN];
ll lazy[maxN * 4];

void update(int si, int ss, int se, int qs, int qe, ll val)
{
    if (lazy[si])
    {
        segTree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] += (se - ss + 1) * val;

        if (ss != se)
            lazy[2 * si] += val, lazy[2 * si + 1] += val;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);

    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        segTree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void solve()
{
    int n, c, code, a, b;
    ll val;
    cin >> n >> c;

    REP(i,1,n*4+1)
    segTree[i] = lazy[i] = 0;

    while (c--)
    {
        cin >> code;

        if (code == 0)
        {
            cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        }
        else
        {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }
    }
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}