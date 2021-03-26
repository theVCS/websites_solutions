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

ll n;

bool f(ll h, ll n)
{
    return (h * (3 * h + 1) / 2) <= n;
}

ll bs(ll n)
{
    int start = 0, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (f(mid, n) && f(mid + 1, n) == false)
        {
            return mid;
        }
        else if (f(mid, n))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

void solve()
{
    cin >> n;
    int cnt = 0;

    while (n > 1)
    {
        cnt++;
        ll x = bs(n);
        n -= (x * (3 * x + 1)) / 2;
    }

    cout << cnt << endl;
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