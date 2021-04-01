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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct segment
{
    ll num;
    int cnt;
};

ll arr[maxN];
segment segTree[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].num = arr[ss];
        segTree[si].cnt = 1;
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
    if (qs > se || qe < ss)
    {
        return INT_MAX;
    }

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return min(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
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
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);
    segTree[si] = min(segTree[2 * si], segTree[2 * si + 1]);
}

void solve()
{
    int n, m, code;
    ll a, b;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
    }
    build(1, 1, n);

    while (m--)
    {
        cin >> code >> a >> b;

        if (code == 1)
        {
            arr[a + 1] = b;
            update(1, 1, n, a + 1);
        }
        else
        {
            cout << query(1, 1, n, a + 1, b) << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}