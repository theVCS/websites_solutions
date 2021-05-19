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

int arr[10001];

int query(int t, int i, int j, int x)
{
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int maxIndex(int n)
{
    for (int i = 1; i < n; i += 2)
    {
        int res = query(1, i, i + 1, n - 1);

        if (res == n)
            return i + 1;
        else if (res == n - 1)
        {
            res = query(1, i + 1, i, n - 1);

            if (res == n)
                return i;
        }
    }

    return n;
}

void solve()
{
    int n;
    cin >> n;

    int j = maxIndex(n);

    arr[j] = n;

    REP(i, 1, n)
    {
        if (i == j)
            continue;

        arr[i] = query(2, i, j, 1);
    }

    cout << "! ";
    REP(i, 1, n)
    cout << arr[i] << " ";

    cout << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}