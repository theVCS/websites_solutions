#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int segTree[800001];
int n;

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = 1;
    }
    else
    {
        int mid = (ss + se) / 2;

        if (qi <= mid)
            update(2 * si, ss, mid, qi);
        else
            update(2 * si + 1, mid + 1, se, qi);

        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

int q(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return (q(2 * si, ss, mid, qs, qe) + q(2 * si + 1, mid + 1, se, qs, qe));
}


int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();

    int res;
    cin >> res;
    res += q(1, 1, n, l, r);
    res = r - l + 1 - res;
    return res;
}

int findKth(int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    else
    {
        int mid = (l + r) / 2;
        int zeroCnt = query(l, mid);

        if (zeroCnt >= k)
        {
            return findKth(l, mid, k);
        }
        else
        {
            return findKth(mid + 1, r, k - zeroCnt);
        }
    }
}

void solve()
{
    int t, k;
    cin >> n >> t;

    while (t--)
    {
        cin >> k;
        int ans = findKth(1, n, k);
        cout << "! " << ans << endl;
        cout.flush();
        update(1, 1, n, ans);
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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