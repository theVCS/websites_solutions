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

int n, m;
ll arr[maxN];
ll segTree[maxN * 4];

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
        segTree[si] = min(segTree[2 * si], segTree[2 * si + 1]);
    }
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
    {
        return __LONG_LONG_MAX__;
    }

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    ll res1 = query(2 * si, ss, mid, qs, qe);
    ll res2 = query(2 * si + 1, mid + 1, se, qs, qe);
    return min(res1, res2);
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        update(2 * si, ss, mid, qi);
    }
    else
    {
        update(2 * si + 1, mid + 1, se, qi);
    }
    segTree[si] = min(segTree[2 * si], segTree[2 * si + 1]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;
    ll l, r;

    cin >> n >> m;

    REP(i, 1, n + 1)
    cin >> arr[i];

    build(1, 1, n);

    while (m--)
    {
        cin >> c >> l >> r;

        if (c == 2)
        {
            cout << query(1, 1, n, l, r) << endl;
        }
        else
        {
            arr[l] = r;
            update(1, 1, n, l);
        }
    }

    return 0;
}