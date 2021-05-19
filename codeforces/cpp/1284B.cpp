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
#define maxN 1000011
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

vector<pii> vec;
int ft[maxN];

void update(int index, ll val)
{
    while (index < maxN)
    {
        ft[index] += val;
        index += (index & -1 * index);
    }
}

ll query(int index)
{
    ll sum = 0;

    while (index)
    {
        sum += ft[index];
        index -= (index & -1 * index);
    }

    return sum;
}

void solve()
{
    int n, dum;
    cin >> n;

    REP(I, 1, n)
    {
        int mx = -INF;
        int mn = INF;
        int k;
        cin >> k;

        REP(i, 1, k)
        {
            cin >> dum;
            dum++;
            mx = max(mx, dum);
            mn = min(mn, dum);
        }
        vec.push_back({mx, mn});
    }

    ll res = 0;

    for (pii e : vec)
    {
        update(e.second, 1);
    }

    for (pii e : vec)
    {
        cout << e.first << " " << e.second << endl;
        cout << query(e.first - 1) << endl;
    }

    cout << res;
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