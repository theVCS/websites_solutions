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
#define maxN 200011
#define endl "\n"
#define INF 100000000000
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
ll oddMeven[maxN];
ll suffixEmin[maxN];
ll suffixOmin[maxN];

void solve()
{
    ll even = 0, odd = 0, ans = INF;

    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];

        if (i & 1)
        {
            odd += arr[i];
        }
        else
        {
            even += arr[i];
        }

        oddMeven[i] = odd - even;
    }

    suffixEmin[n + 1] = INF;
    suffixOmin[n + 1] = INF;

    RREP(i, n, 1)
    {
        if (i & 1)
        {
            suffixOmin[i] = min(suffixOmin[i + 1], oddMeven[i]);
            suffixEmin[i] = suffixEmin[i + 1];

            ans = min(ans, suffixEmin[i] - oddMeven[i - 1]);
        }
        else
        {
            suffixEmin[i] = min(suffixEmin[i + 1], oddMeven[i]);
            suffixOmin[i] = suffixOmin[i + 1];

            ans = min(ans, suffixOmin[i] - oddMeven[i - 1]);
        }
    }

    cout << max(odd, odd - ans) << endl;
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