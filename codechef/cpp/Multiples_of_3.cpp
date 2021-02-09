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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct segment
{
    int m0, m1, m2;
} segTree[4 * maxN];
int lazy[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].m0 = 1;
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si].m0 = segTree[2 * si].m0 + segTree[2 * si + 1].m0;
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si] != 0)
    {
        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        int dx = lazy[si] % 3;

        if (dx == 1)
        {
            swap(segTree[si].m0, segTree[si].m1);
            swap(segTree[si].m0, segTree[si].m2);
        }
        else if (dx == 2)
        {
            swap(segTree[si].m0, segTree[si].m2);
            swap(segTree[si].m0, segTree[si].m1);
        }

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
        return segTree[si].m0;

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si] != 0)
    {
        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        int dx = lazy[si] % 3;

        if (dx == 1)
        {
            swap(segTree[si].m0, segTree[si].m1);
            swap(segTree[si].m0, segTree[si].m2);
        }
        else if (dx == 2)
        {
            swap(segTree[si].m0, segTree[si].m2);
            swap(segTree[si].m0, segTree[si].m1);
        }

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        swap(segTree[si].m0, segTree[si].m1);
        swap(segTree[si].m0, segTree[si].m2);

        if (ss != se)
            lazy[2 * si] += 1, lazy[2 * si + 1] += 1;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);
    segTree[si].m0 = segTree[si * 2].m0 + segTree[si * 2 + 1].m0;
    segTree[si].m1 = segTree[si * 2].m1 + segTree[si * 2 + 1].m1;
    segTree[si].m2 = segTree[si * 2].m2 + segTree[si * 2 + 1].m2;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m;
    int code, l, r;

    // cin >> n >> m;
    scanf("%d %d", &n, &m);

    // calculated total multiples of 3
    build(1, 1, n);

    while (m--)
    {
        // cin >> code >> l >> r;
        scanf("%d %d %d", &code, &l, &r);

        l++, r++;

        if (code == 0)
        {
            // update each number by one
            update(1, 1, n, l, r);
        }
        else
        {
            // process query
            // cout << query(1, 1, n, l, r) << endl;
            printf("%d\n", query(1,1,n,l,r));
        }
    }

    return 0;
}