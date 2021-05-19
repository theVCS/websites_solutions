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

ll arr[10];

int counter(ll a)
{
    int cnt = 0;

    while (a)
    {
        a /= 10;
        cnt++;
    }

    return cnt;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    ll x = arr[c];
    ll y = arr[c];

    while (counter(x) < a)
    {
        x *= 2;
    }
    
    while (counter(y) < b)
    {
        y *= 3;
    }

    // cout<<counter(mod)<<endl;

    cout<<x<<" "<<y<<endl;
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

    arr[1] = 2;
    arr[2] = 11;
    arr[3] = 101;
    arr[4] = 1009;
    arr[5] = 10007;
    arr[6] = 100003;
    arr[7] = 1000003;
    arr[8] = 10000019;
    arr[9] = 100000007;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}