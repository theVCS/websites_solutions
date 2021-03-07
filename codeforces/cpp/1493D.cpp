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
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN], segTree[4 * maxN];
int n, m;

void buildTree(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        buildTree(2 * si, ss, mid);
        buildTree(2 * si + 1, mid + 1, se);
        segTree[si] = __gcd(segTree[2 * si], segTree[2 * si + 1]);
    }
}

void update(int si, int ss, int se, int qi, int val)
{
    if (ss == se)
    {
        segTree[si] *= val;
        return;
    }

    int mid = (ss + se) / 2;
    if (qi <= mid)
        update(2 * si, ss, mid, qi, val);
    else
        update(2 * si + 1, mid + 1, se, qi, val);

    segTree[si] = __gcd(segTree[2 * si], segTree[2 * si + 1]);
}

void solve()
{
    int n, q, index, val;

    cin >> n >> q;

    REP(i, 1, n + 1)
    cin >> arr[i];

    buildTree(1,1,n);

    REP(i, 0, q)
    {
        cin >> index >> val;
        update(1, 1, n, index, val);
        cout << segTree[1] << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}