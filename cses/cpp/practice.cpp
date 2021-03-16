#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 2001
#define INF 0x3f3f3f3f
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int arr[maxN][maxN];

int ini_seg[maxN][4 * maxN];
int segTree[4 * maxN][4 * maxN];
int maxC, n, m;

void subBuild(int si, int ss, int se, int row)
{
    if (ss == se)
    {
        ini_seg[row][si] = arr[row][ss];
        maxC = max(maxC, si);
    }
    else
    {
        int mid = (ss + se) / 2;
        subBuild(2 * si, ss, mid, row);
        subBuild(2 * si + 1, mid + 1, se, row);
        ini_seg[row][si] = ini_seg[row][2 * si] + ini_seg[row][2 * si + 1];
    }
}

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        REP(i, 1, maxC + 1)
        {
            segTree[si][i] = ini_seg[ss][i];
        }
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        REP(i, 1, maxC + 1)
        segTree[si][i] = segTree[2 * si][i] + segTree[2 * si + 1][i];
    }
}

int query_ini(int si, int ss, int se, int qs, int qe, int row)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[row][si];
    }

    int mid = (ss + se) / 2;
    return query_ini(2 * si, ss, mid, qs, qe, row) + query_ini(2 * si + 1, mid + 1, se, qs, qe, row);
}

int query(int si, int ss, int se, int x1, int x2, int y1, int y2)
{
    if (ss > x2 || se < x1)
        return 0;

    if (x1 <= ss && x2 >= se)
    {
        return query_ini(1, 1, m, y1, y2, si);
    }

    int mid = (ss + se) / 2;

    return query(2 * si, ss, mid, x1, x2, y1, y2) + query(2 * si + 1, mid + 1, se, x1, x2, y1, y2);
}

void update_ini(int si, int ss, int se, int y, int row, int val)
{
    if (ss == se)
    {
        segTree[row][si] = val;
        return;
    }
    int mid = (ss + se) / 2;

    if (y <= mid)
        update_ini(2 * si, ss, mid, y, row, val);
    else
        update_ini(2 * si + 1, mid + 1, se, y, row, val);

    segTree[row][si] = segTree[row][2 * si] + segTree[row][2 * si + 1];
}

void update(int si, int ss, int se, int x, int y, int val)
{
    if (ss == se)
    {
        update_ini(1, 1, m, y, si, val);
        return;
    }

    int mid = (ss + se) / 2;

    if (x <= mid)
        update(2 * si, ss, mid, x, y, val);
    else
        update(2 * si + 1, mid + 1, se, x, y, val);

    REP(i, 1, maxC + 1)
    segTree[si][i] = segTree[2 * si][i] + segTree[2 * si + 1][i];
}

void solve()
{
    int x1, y1, x2, y2;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];
        }
    }

    REP(i, 1, n + 1)
    subBuild(1, 1, m, i);

    build(1, 1, n);

    int q, code;

    cin >> q;

    while (q--)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> x1 >> y1 >> y2;
            update(1, 1, n, x1, y1, y2);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(1, 1, n, x1, x2, y1, y2) << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}