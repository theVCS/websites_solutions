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
#define maxN 100001
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

int n;
ll arr[maxN];

int sorter(int l, int r, int nthBit)
{
    int i = l, j = l - 1;

    while (i <= r)
    {
        if ((arr[i] & 1<<nthBit) == 0)
        {
            swap(arr[i], arr[++j]);
        }

        i++;
    }

    return j;
}

ll fun(int l, int r, int nthBit)
{
    if (nthBit < 0)
        return 0;

    int mid = sorter(l, r, nthBit);
    int notSetB = mid - l + 1;
    int setB = r - mid;

    // cout<<notSetB<<" "<<setB<<endl;

    if (notSetB == 0)
        return fun(mid + 1, r, nthBit - 1);
    if (setB == 0)
        return fun(l, mid, nthBit - 1);
    if (notSetB && setB)
        return min(fun(l, mid, nthBit - 1), fun(mid + 1, r, nthBit - 1)) + (1LL << nthBit);
}

void solve()
{
    cin >> n;

    int mx = 0;

    REP(i, 1, n)
    {
        cin >> arr[i];

        REP(j, 1, 30)
        {
            if (arr[i] & 1LL << j)
            {
                mx = max(mx, j);
            }
        }
    }
    // cout<<mx<<endl;
    cout << fun(1, n, mx);
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