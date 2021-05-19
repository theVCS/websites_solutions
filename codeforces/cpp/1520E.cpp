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

vector<int> arr;
ll prefix[maxN];

ll sum(ll n)
{
    if (n < 0)
        return 0;
    return (n * (n + 1)) / 2;
}

ll range(ll r, ll l)
{
    l--;
    if (r <= l)
        return 0;
    return (sum(r) - sum(l));
}

void solve()
{
    arr.clear();

    int n;
    string s;

    cin >> n;
    cin >> s;

    REP(i, 0, n - 1)
    {
        if (s[i] == '*')
            arr.push_back(i + 1);
    }

    n = arr.size();

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    REP(i, 1, n)
    {
        prefix[i] = 0;
        prefix[i] = arr[i - 1] + prefix[i - 1];
    }

    ll ans = __LONG_LONG_MAX__;

    REP(i, 1, n)
    {
        int ele = i - 1;

        ll v1 = 0, v2 = 0;


        if (ele)
        {
            v1 = range(arr[i - 1] - 1, arr[i - 1] - ele) - prefix[i - 1];
        }

        ele = n - i;

        if (ele)
        {
            v2 = (prefix[n] - prefix[i]) - range(arr[i - 1] + ele, arr[i - 1] + 1);
        }

        ans = min(ans, v1 + v2);
    }

    cout << ans << endl;
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