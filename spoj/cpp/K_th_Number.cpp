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

pii arr[maxN];
int ar[maxN];
vector<int> segTree[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back(arr[ss].second);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        merge(all(segTree[2 * si]), all(segTree[2 * si + 1]), back_inserter(segTree[si]));
    }
}

int query(int si, int ss, int se, int qs, int qe, int k)
{
    if (ss == se)
    {
        return segTree[si][0];
    }

    int mid = (ss + se) / 2;
    int x = upper_bound(all(segTree[2 * si]), qe) - lower_bound(all(segTree[2 * si]), qs);

    if (x >= k)
        return query(2 * si, ss, mid, qs, qe, k);
    else
        return query(2 * si + 1, mid + 1, se, qs, qe, k - x);
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m;

    scanf("%d %d", &n, &m);

    REP(i, 1, n + 1)
    {
        scanf("%d", ar + i);
        arr[i].first = ar[i];
        arr[i].second = i;
    }

    sort(arr + 1, arr + 1 + n);

    build(1, 1, n);

    while (m--)
    {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        int ans = query(1, 1, n, l, r, x);
        printf("%d\n", ar[ans]);
    }

    return 0;
}
