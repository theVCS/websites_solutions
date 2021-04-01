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

int arr[maxN], prevArr[maxN];
int segTree[4 * maxN], lazy[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
    }
}

int query(int si, int ss, int se, int k)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss == se)
    {
        return ss;
    }

    int mid = (ss + se) / 2;
    int leftChild = 2 * si;
    int rightChild = 2 * si + 1;

    if (segTree[leftChild] + lazy[2 * si] < k)
    {
        return query(rightChild, mid + 1, se, k);
    }
    else
    {
        return query(leftChild, ss, mid, k);
    }
}

void update(int si, int ss, int se, int qs, int qe, int v)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (qs > se || qe < ss)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] += v;

        if (ss != se)
            lazy[2 * si] += v, lazy[2 * si + 1] += v;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, v);
    update(2 * si + 1, mid + 1, se, qs, qe, v);
    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

void print(int si, int ss, int se)
{
    if (lazy[si])
    {
        segTree[si] += lazy[si];

        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];

        lazy[si] = 0;
    }

    if (ss == se)
    {
        // cout << si << " -> " << segTree[si] << " ";
        return;
    }

    int mid = (ss + se) / 2;
    print(2 * si, ss, mid);
    print(2 * si + 1, mid + 1, se);
    // cout << si << " -> " << segTree[si] << " ";
}

void solve()
{
    int n, m, code, a;
    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        prevArr[i] = arr[i];
        arr[i] += arr[i - 1];
    }

    build(1, 1, n);

    while (m--)
    {
        cin >> code >> a;
        a++;

        if (code == 1)
        {
            if (prevArr[a] == 0)
            {
                update(1, 1, n, a, n, 1);
                prevArr[a] = 1;
            }
            else
            {
                update(1, 1, n, a, n, -1);
                prevArr[a] = 0;
            }

            // print(1, 1, n);
            // cout << endl;
        }
        else
        {
            cout << query(1, 1, n, a) - 1 << endl;
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