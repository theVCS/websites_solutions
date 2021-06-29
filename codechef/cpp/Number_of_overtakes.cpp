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
int speed[maxN];
int pos[maxN];
int speX[maxN];
ll ft[10000001];

void update(int index)
{
    while (index <= 10000001)
    {
        ft[index]++;
        index += (index & -index);
    }
}

ll query(int index)
{
    ll res = 0;

    while (index)
    {
        res += ft[index];
        index -= (index & -index);
    }

    return res;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> speed[i];
    REP(i, 1, n)
    cin >> pos[i];

    REP(i, 1, n)
    speX[pos[i]] = speed[i];

    ll res = 0;

    RREP(i, n, 1)
    {
        res += query(speX[i] - 1);
        update(speX[i]);
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

    // cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}