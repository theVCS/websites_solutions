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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int segTree[4 * maxN], lazy[4 * maxN];
vector<int> arr;

void build(int si, int ss, int se)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si] * (se - ss + 1);

        if (ss != se)
            lazy[si * 2] += lazy[si], lazy[si * 2 + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss == se)
    {
        arr.push_back(segTree[si]);
    }
    else
    {
        int mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        segTree[si] = segTree[si * 2] + segTree[si * 2 + 1];
    }
}

void update(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si] * (se - ss + 1);

        if (ss != se)
            lazy[si * 2] += lazy[si], lazy[si * 2 + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] += (se - ss + 1);

        if (ss != se)
            lazy[si * 2] += 1, lazy[si * 2 + 1] += 1;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);
    segTree[si] = segTree[si * 2] + segTree[si * 2 + 1];
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m, l, r, q, x;

    // cin >> n >> m;
    scanf("%d %d", &n, &m);

    while (m--)
    {
        // cin >> l >> r;
        scanf("%d %d", &l, &r);
        update(1, 1, n, l, r);
    }

    build(1, 1, n);

    sort(arr.begin(), arr.end());

    // cin >> q;
    scanf("%d", &q);

    while (q--)
    {
        // cin >> x;
        scanf("%d", &x);
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        // cout << arr.size() - index << endl;
        printf("%d\n", (arr.size() - index));
    }

    return 0;
}