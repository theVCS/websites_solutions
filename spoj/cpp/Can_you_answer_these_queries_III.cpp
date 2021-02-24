#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 50001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int segTree[4 * maxN];
int ans;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss], 0;
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qi);
    update(2 * si + 1, mid + 1, se, qi);
    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m, code, a, b;

    // cin >> n;
    scanf("%d", &n);

    REP(i, 1, n + 1)
    {
        scanf("%d", arr + i);
    }

    build(1, 1, n);

    scanf("%d", &m);

    while (m--)
    {
        cin >> code >> a >> b;

        if (code)
        {
            ans = INT_MIN;
            printf("%d\n", query(1, 1, n, a, b));
        }
        else
        {
            arr[a] = b;
            update(1, 1, n, a);
        }
    }

    return 0;
}