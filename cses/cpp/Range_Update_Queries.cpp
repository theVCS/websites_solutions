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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN], segTree[4 * maxN], lazy[4 * maxN];

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
        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si] != 0)
    {
        segTree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
        {
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (qs > se || qe < ss)
    {
        return 0;
    }

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qs, int qe, ll val)
{
    if (lazy[si] != 0)
    {
        segTree[si] += (se - ss + 1) * lazy[si];

        if (ss != se)
        {
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > qe || se < qs)
    {
        return;
    }

    if (qs <= ss && qe >= se)
    {
        segTree[si] += val * (se - ss + 1);

        if (ss != se)
        {
            lazy[2 * si] += val, lazy[2 * si + 1] += val;
        }

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);
    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, code, l, r;
    ll val;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (m--)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else
        {
            cin >> l;
            cout << query(1, 1, n, l, l) << endl;
        }
    }

    return 0;
}