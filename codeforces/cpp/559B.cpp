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
#define maxN 200001
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

string s, t;
ll dps[maxN], dpt[maxN], po[maxN];

void init()
{
    ll power = 103, p = 103;
    dps[0] = s[0] - 'a' + 1;
    dpt[0] = t[0] - 'a' + 1;
    po[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        dps[i] = (dps[i - 1] + (s[i] - 'a' + 1) * p) % mod;
        dpt[i] = (dpt[i - 1] + (t[i] - 'a' + 1) * p) % mod;
        po[i] = p;
        p = (p * power) % mod;
    }
}

ll getSubHashS(int l, int r)
{
    ll res = dps[r];

    if (l)
        res = (res - dps[l - 1] + mod) % mod;

    return res;
}

ll getSubHashT(int l, int r)
{
    ll res = dpt[r];

    if (l)
        res = (res - dpt[l - 1] + mod) % mod;

    return res;
}

bool stringEqual(int l1, int r1, int l2, int r2)
{
    ll v1 = (getSubHashS(l1, r1) * po[l2]) % mod;
    ll v2 = (getSubHashT(l2, r2) * po[l1]) % mod;

    // cout << v1 << " " << v2 << endl;

    if (v1 == v2)
    {
        return true;
    }

    return false;
}

bool fun(int l1, int r1, int l2, int r2)
{
    if (stringEqual(l1, r1, l2, r2))
        return true;

    if ((r1 - l1 + 1) & 1)
        return false;

    int mid1 = (l1 + r1) / 2;
    int mid2 = (l2 + r2) / 2;

    if (fun(l1, mid1, mid2 + 1, r2) && fun(mid1 + 1, r1, l2, mid2))
        return true;

    if (fun(l1, mid1, l2, mid2) && fun(mid1 + 1, r1, mid2 + 1, r2))
        return true;

    return false;
}

void solve()
{
    cin >> s >> t;
    int n = s.size();

    init();

    if (fun(0, n - 1, 0, n - 1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
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