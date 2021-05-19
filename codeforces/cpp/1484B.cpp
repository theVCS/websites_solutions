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

void solve()
{
    cin >> n;

    cin >> arr[1];
    ll mx = arr[1];

    set<ll> s;

    REP(i, 2, n)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        s.insert(arr[i] - arr[i - 1]);
    }

    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }

    if (s.size() > 2)
    {
        cout << -1 << endl;
        return;
    }

    if (s.size() == 1)
    {
        cout << 0 << endl;
        return;
    }

    ll ele1 = *s.begin();
    s.erase(ele1);
    ll ele2 = *s.begin();

    if ((ele1 <= 0 && ele2 <= 0) || (ele1 >= 0 && ele2 >= 0))
    {
        cout << -1 << endl;
        return;
    }

    if (ele2 - ele1 <= mx)
    {
        cout << -1 << endl;
        return;
    }

    cout << ele2 - ele1 << " " << ele2 << endl;
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