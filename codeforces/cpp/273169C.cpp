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

        if (segTree[2 * si].num == segTree[2 * si + 1].num)
        {
            segTree[si].num = segTree[2 * si].num;
            segTree[si].cnt = segTree[2 * si].cnt + segTree[2 * si + 1].cnt;
        }
        else if (segTree[2 * si].num < segTree[2 * si + 1].num)
        {
            segTree[si].num = segTree[2 * si].num;
            segTree[si].cnt = segTree[2 * si].cnt;
        }
        else
        {
            segTree[si].num = segTree[2 * si + 1].num;
            segTree[si].cnt = segTree[2 * si + 1].cnt;
        }
    }
}

pair<ll, int> query(int si, int ss, int se, int qs, int qe)
{
    if (qs > se || qe < ss)
    {
        return {INT_MAX, 0};
    }

    if (qs <= ss && qe >= se)
    {
        return {segTree[si].num, segTree[si].cnt};
    }

    pair<ll, int> l, r;

    int mid = (ss + se) / 2;

    l = query(2 * si, ss, mid, qs, qe);
    r = query(2 * si + 1, mid + 1, se, qs, qe);

    if (l.first == r.first)
    {
        return {l.first, l.second + r.second};
    }
    else if (l.first < r.first)
    {
        return l;
    }
    else
    {
        return r;
    }
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = {arr[ss], 1};
        return;
    }

    int mid = (ss + se) / 2;
    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    if (segTree[2 * si].num == segTree[2 * si + 1].num)
    {
        segTree[si].num = segTree[2 * si].num;
        segTree[si].cnt = segTree[2 * si].cnt + segTree[2 * si + 1].cnt;
    }
    else if (segTree[2 * si].num < segTree[2 * si + 1].num)
    {
        segTree[si].num = segTree[2 * si].num;
        segTree[si].cnt = segTree[2 * si].cnt;
    }
    else
    {
        segTree[si].num = segTree[2 * si + 1].num;
        segTree[si].cnt = segTree[2 * si + 1].cnt;
    }
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
            pair<ll, int> ans = query(1, 1, n, a + 1, b);
            cout << ans.first << " " << ans.second << endl;
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