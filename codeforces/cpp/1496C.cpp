#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<ll> x, y;

void solve()
{
    x.clear(), y.clear();

    int n;
    ll a, b;

    cin >> n;

    REP(i, 0, 2 * n)
    {
        cin >> a >> b;

        if (a == 0)
            x.push_back(abs(b));
        else
            y.push_back(abs(a));
    }

    sort(all(x));
    sort(all(y));

    long double res = 0;

    REP(i, 0, min(y.size(), x.size()))
    {
        ll a1 = x[i] * x[i];
        ll a2 = y[i] * y[i];
        res += sqrt(a1 + a2);
    }

    cout << fixed << setprecision(12) << res << endl;
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