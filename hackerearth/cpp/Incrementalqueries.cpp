#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];

struct segment
{
    ll evenSum, oddSum, maxValue;
    int oddCnt, evenCnt;

    void fun(segment a, segment b)
    {
        evenCnt = a.evenCnt + b.evenCnt;
        oddCnt = a.oddCnt + b.oddCnt;
        evenSum = a.evenSum + b.evenSum;
        oddSum = a.oddSum + b.oddSum;
        maxValue = max(a.maxValue, b.maxValue);
    }

    void init()
    {
        evenCnt = 0;
        oddCnt = 0;
        evenSum = 0;
        oddSum = 0;
        maxValue = 0;
    }

} segTree[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].maxValue = arr[ss];

        if (arr[ss] & 1)
            segTree[si].oddCnt = 1, segTree[si].oddSum = arr[ss];
        else
            segTree[si].evenCnt = 1, segTree[si].evenSum = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        segTree[si].fun(segTree[2 * si], segTree[2 * si + 1]);
    }
}

segment query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return {0, 0, 0, 0, 0};

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    segment ele;
    ele.init();
    ele.fun(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
    return ele;
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si].init();

        segTree[si].maxValue = arr[ss];

        if (arr[ss] & 1)
            segTree[si].oddCnt = 1, segTree[si].oddSum = arr[ss];
        else
            segTree[si].evenCnt = 1, segTree[si].evenSum = arr[ss];

        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    segTree[si].init();
    segTree[si].fun(segTree[2 * si], segTree[2 * si + 1]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, code;
    ll a, b;

    cin >> n >> m;

    REP(i, 1, n + 1)
    cin >> arr[i];

    build(1, 1, n);

    while (m--)
    {
        cin >> code >> a >> b;

        if (code == 1)
        {
            arr[a] = b;
            update(1, 1, n, a);
        }
        else
        {
            segment e = query(1, 1, n, a, b);
            ll res;

            if (e.maxValue & 1)
            {
                ll q1 = (e.maxValue * e.evenCnt - e.evenSum) / 2 - e.evenCnt / 2 + e.evenCnt;
                ll q2 = (e.maxValue * e.oddCnt - e.oddSum) / 2;
                res = q1 + q2;
            }
            else
            {
                ll q1 = (e.maxValue * e.evenCnt - e.evenSum) / 2;
                ll q2 = (e.maxValue * e.oddCnt - e.oddSum) / 2 - e.oddCnt / 2 + e.oddCnt;
                res = q1 + q2;
            }

            cout << res << endl;
        }
    }

    return 0;
}