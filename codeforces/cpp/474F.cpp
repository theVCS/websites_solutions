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

int arr[maxN];

struct SegTree
{
    int val, cnt, gcd;
} segTree[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].val = segTree[si].gcd = arr[ss];
        segTree[si].cnt = 1;
    }
    else
    {
        int mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        if (segTree[2 * si].val < segTree[2 * si + 1].val)
        {
            segTree[si].val = segTree[2 * si].val;
            segTree[si].cnt = segTree[2 * si].cnt;
        }
        else if (segTree[2 * si].val > segTree[2 * si + 1].val)
        {
            segTree[si].val = segTree[2 * si + 1].val;
            segTree[si].cnt = segTree[2 * si + 1].cnt;
        }
        else
        {
            segTree[si].val = segTree[2 * si + 1].val;
            segTree[si].cnt = segTree[2 * si + 1].cnt + segTree[2 * si].cnt;
        }

        segTree[si].gcd = __gcd(segTree[si * 2].gcd, segTree[2 * si + 1].gcd);
    }
}

SegTree query(int si, int ss, int se, int qs, int qe)
{

    if (ss > qe || se < qs)
    {
        SegTree temp;
        temp.cnt = temp.val = INT_MAX;
        temp.gcd = 0;
        return temp;
    }

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;

    SegTree ans1 = query(2 * si, ss, mid, qs, qe);
    SegTree ans2 = query(2 * si + 1, mid + 1, se, qs, qe);
    SegTree ans;

    ans.val = min(ans1.val, ans2.val);

    // calculating minimum
    if (ans1.val == ans2.val)
        ans.cnt = ans2.cnt + ans1.cnt;
    else if (ans1.val < ans2.val)
        ans.cnt = ans1.cnt;
    else
        ans.cnt = ans2.cnt;

    // computing gcds
    ans.gcd = __gcd(ans1.gcd, ans2.gcd);

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n;

    REP(i, 1, n + 1)
    cin >> arr[i];

    build(1, 1, n);

    cin >> m;

    while (m--)
    {
        cin >> a >> b;

        SegTree s = query(1, 1, n, a, b);

        if (s.gcd == s.val)
        {
            cout << b - a + 1 - s.cnt << endl;
        }
        else
        {
            cout << b - a + 1 << endl;
        }
    }

    return 0;
}