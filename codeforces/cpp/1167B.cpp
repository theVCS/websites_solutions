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

int query(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    fflush(stdout);

    int val;
    cin >> val;
    return val;
}

int parser(int val)
{
    if(val % 23 == 0)
    {
        return 23;
    }
    else if (val % 7 == 0)
    {
        return 42;
    }
    else if (val % 5 == 0)
    {
        return 15;
    }
    else
    {
        int p = log2(val);

        if (p == 5)
        {
            return 4;
        }
        else if (p == 6)
        {
            return 4;
        }
        else
        {
            return 8;
        }
    }
}

void solve()
{
    int arr[7];

    int res1 = query(1, 2);
    int res2 = query(1, 3);

    int n1 = parser(res1);
    int n2 = res1 / n1;

    int n3 = parser(res2);
    int n4 = res2 / n3;

    if ((n1 == n3) || (n1 == n4))
    {
        arr[1] = n1;
        arr[2] = res1 / n1;
        arr[3] = res2 / n1;
    }
    else
    {
        arr[1] = n2;
        arr[2] = res1 / n2;
        arr[3] = res2 / n2;
    }

    res1 = query(4, 5);
    res2 = query(4, 6);

    n1 = parser(res1);
    n2 = res1 / n1;

    n3 = parser(res2);
    n4 = res2 / n3;

    if ((n1 == n3) || (n1 == n4))
    {
        arr[4] = n1;
        arr[5] = res1 / n1;
        arr[6] = res2 / n1;
    }
    else
    {
        arr[4] = n2;
        arr[5] = res1 / n2;
        arr[6] = res2 / n2;
    }

    cout << "! ";
    REP(i, 1, 6)
    cout << arr[i] << " ";
    cout << endl;
    fflush(stdout);
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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