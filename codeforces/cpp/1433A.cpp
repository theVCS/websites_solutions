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

vector<int> vec[11];

void solve()
{
    int n;
    cin >> n;

    ll res = 0;

    REP(i, 1, 9)
    {
        REP(j, 0, 3)
        {
            res += j + 1;
            if (vec[i][j] == n)
            {
                cout << res << endl;
                return;
            }
        }
    }
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

    vec[1] = {1, 11, 111, 1111};
    vec[2] = {2, 22, 222, 2222};
    vec[3] = {3, 33, 333, 3333};
    vec[4] = {4, 44, 444, 4444};
    vec[5] = {5, 55, 555, 5555};
    vec[6] = {6, 66, 666, 6666};
    vec[7] = {7, 77, 777, 7777};
    vec[8] = {8, 88, 888, 8888};
    vec[9] = {9, 99, 999, 9999};
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