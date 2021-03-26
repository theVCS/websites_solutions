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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int res[maxN];
int res2[maxN];
int segTree[4 * maxN];
int segTree2[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = ss;
        segTree2[si] = ss;
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
        segTree2[si] = min(segTree2[2 * si], segTree2[2 * si + 1]);
    }
}

// first is minimum and second is max
int queryMin(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
    {
        return INT_MAX;
    }

    if (ss >= qs && se <= qe)
    {
        return segTree2[si];
    }

    int mid = (ss + se) / 2;
    int l = queryMin(2 * si, ss, mid, qs, qe);
    int r = queryMin(2 * si + 1, mid + 1, se, qs, qe);
    return min(l, r);
}

int queryMax(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
    {
        return INT_MIN;
    }

    if (ss >= qs && se <= qe)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    int l = queryMax(2 * si, ss, mid, qs, qe);
    int r = queryMax(2 * si + 1, mid + 1, se, qs, qe);
    return max(l, r);
}

void updateMax(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = INT_MIN;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        updateMax(2 * si, ss, mid, qi);
    else
        updateMax(2 * si + 1, mid + 1, se, qi);

    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

void updateMin(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree2[si] = INT_MAX;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        updateMin(2 * si, ss, mid, qi);
    else
        updateMin(2 * si + 1, mid + 1, se, qi);

    segTree2[si] = min(segTree2[2 * si], segTree2[2 * si + 1]);
}

void solve()
{
    int n;

    cin >> n;

    build(1, 1, n);

    REP(i, 1, n + 1)
    {
        res[i] = res2[i] = 0;

        cin >> arr[i];

        if (arr[i] != arr[i - 1])
        {
            res[i] = arr[i];
            res2[i] = arr[i];
            updateMax(1, 1, n, arr[i]);
            updateMin(1, 1, n, arr[i]);
        }
    }

    REP(i, 1, n + 1)
    {
        if (res[i] == 0)
        {
            int temp;
            temp = queryMax(1, 1, n, 1, arr[i] - 1);
            updateMax(1, 1, n, temp);
            res[i] = temp;

            // cout << temp << endl;

            temp = queryMin(1, 1, n, 1, arr[i] - 1);
            updateMin(1, 1, n, temp);
            res2[i] = temp;

            // cout <<  temp << endl;
        }
    }

    REP(i, 1, n + 1)
    {
        cout << res2[i] << " ";
    }
    cout << endl;
    REP(i, 1, n + 1)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}