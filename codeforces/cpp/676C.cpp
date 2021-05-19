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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;

int fun(int n, int k, int a = 0, int b = 0, int val = 0)
{
    if (n == 0)
    {
        return val;
    }
    else if (k)
    {
        if (s[n - 1] == 'a')
        {
            // we can exchange a by b
            int res1 = fun(n - 1, k - 1, 0, b + 1, max({val, a, b + 1}));
            int res2 = fun(n - 1, k, a + 1, 0, max({a + 1, val, b}));

            return max(res1, res2);
        }
        else
        {
            // exchaging b by a
            int res1 = fun(n - 1, k - 1, a + 1, 0, max({val, a + 1, b}));
            int res2 = fun(n - 1, k, 0, b + 1, max({a, val, b + 1}));

            return max(res1, res2);
        }
    }
    else
    {
        if (s[n - 1] == 'a')
        {
            return fun(n - 1, 0, a + 1, 0, max({a + 1, b, val}));
        }
        else
        {
            return fun(n - 1, 0, 0, b + 1, max({val, a, b + 1}));
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cin >> s;
    cout << fun(n, k);
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