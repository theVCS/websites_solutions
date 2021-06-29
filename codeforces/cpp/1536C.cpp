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
#define maxN 500001
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
string s;
int prefixD[maxN];
int prefixK[maxN];

int fun(int l, int r)
{
    if (l == r)
        return 1;

    if (l < r)
    {
        int dnct = prefixD[r + 1] - prefixD[l];
        int knct = prefixK[r + 1] - prefixK[l];

        if(dnct == 0 || knct == 0)
            return max(knct, dnct);

        int mid = -1;
        REP(i, l, r)
        {
            int _dnct1 = prefixD[i + 1] - prefixD[l];
            int _knct1 = prefixK[i + 1] - prefixK[l];
            int _dnct2 = dnct - _dnct1;
            int _knct2 = knct - _knct1;

            if ((_dnct1 * _knct2 * 1LL) == (_dnct2 * _knct1 * 1LL))
            {
                mid = i;
                break;
            }
        }

        if (mid == -1)
            return 1;

        return (fun(l, mid) + fun(mid + 1, r));
    }
}

void solve()
{
    cin >> n;
    cin >> s;

    REP(i, 1, n)
    {
        prefixD[i] = (s[i - 1] == 'D') + prefixD[i - 1];
        prefixK[i] = (s[i - 1] == 'K') + prefixK[i - 1];
    }

    REP(i, 0, n - 1)
    {
        cout << fun(0, i) << " ";
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