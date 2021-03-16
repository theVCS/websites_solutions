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
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
map<int, int> mp;
vector<int> segTree[maxN * 4];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back(arr[ss]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        merge(all(segTree[2 * si]), all(segTree[2 * si + 1]), back_inserter(segTree[si]));
    }
}

int r;

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return (lower_bound(all(segTree[si]), r + 1) - segTree[si].begin());
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

void solve()
{
    int n, m, a, b;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
    }

    for (int i = n; i > 0; i--)
    {
        int temp = arr[i];
        int mpV = mp[temp];

        if (mpV == 0)
        {
            arr[i] = 1000000000;
            mp[temp] = i;
        }
        else
        {
            arr[i] = mpV;
            mp[temp] = i;
        }
    }

    build(1, 1, n);

    while (m--)
    {
        cin >> a >> b;
        r = b;
        cout << (b - a + 1) - query(1, 1, n, a, b) << endl;
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