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

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();

    int res;
    cin >> res;
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
    int n, t, k;
    cin >> n >> t >> k;
    int ans = findKth(1, n, k);
    cout<<"! "<<ans;
    cout.flush();
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