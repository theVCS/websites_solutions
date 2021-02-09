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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];

struct st
{
    int even;
    int odd;
} segTree[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].even = (arr[ss] + 1) % 2;
        segTree[si].odd = (arr[ss]) % 2;
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si].even = segTree[2 * si].even + segTree[2 * si + 1].even;
        segTree[si].odd = segTree[2 * si].odd + segTree[2 * si + 1].odd;
    }
}

st query(int si, int ss, int se, int qs, int qe)
{
    if (qe < ss || qs > se)
    {
        return {0, 0};
    }
    if (ss >= qs && se <= qe)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    st s1 = query(2 * si, ss, mid, qs, qe);
    st s2 = query(2 * si + 1, mid + 1, se, qs, qe);
    return {s1.even + s2.even, s1.odd + s2.odd};
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si].even = (arr[ss] + 1) % 2;
        segTree[si].odd = (arr[ss]) % 2;
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

    segTree[si].even = segTree[2 * si].even + segTree[2 * si + 1].even;
    segTree[si].odd = segTree[2 * si].odd + segTree[2 * si + 1].odd;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c;
    ll l, r;

    cin >> n;

    REP(i, 1, n + 1)
    cin >> arr[i];

    build(1, 1, n);

    cin >> m;

    st obj;

    while (m--)
    {
        cin >> c >> l >> r;

        if (c == 0) // update
        {
            if (arr[l] % 2 != r % 2)
            {
                arr[l] = r;
                update(1, 1, n, l);
            }
        }
        else if (c == 1) //even
        {
            obj = query(1, 1, n, l, r);
            cout << obj.even << endl;
        }
        else // odd
        {
            obj = query(1, 1, n, l, r);
            cout << obj.odd << endl;
        }
    }

    return 0;
}