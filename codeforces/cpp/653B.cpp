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
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, q;
struct query
{
    string a, b;
} arr[37];

int ways(string s, int len)
{
    if (len == 0)
    {
        return int(s == "a");
    }

    int totWays = 0;
    REP(i, 1, q + 1)
    {
        if (s[0] == arr[i].a[0])
            totWays += ways(arr[i].b, len - 1);
    }
    return totWays;
}

void solve()
{
    cin >> n >> q;

    REP(i, 1, q + 1)
    cin >> arr[i].a >> arr[i].b;

    string s;

    int wys = 0;

    REP(i, 1, q + 1)
    {
        s = arr[i].b;
        wys += ways(s, n - 2);
    }

    cout << wys;
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