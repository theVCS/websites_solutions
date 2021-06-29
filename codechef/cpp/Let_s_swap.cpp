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
int arr[maxN];
int pos[maxN];

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    ll val = 0;
    int index1 = 0, index2 = 0;
    ll ans = 0;

    REP(i, 1, n)
    {
        int currPos = pos[i];
        int reqPos = n + 1 - i;

        if (currPos == reqPos)
            continue;

        int res1 = abs(i - currPos) + abs(arr[reqPos] - reqPos);
        int res2 = abs(i - reqPos) + abs(arr[reqPos] - currPos);

        if (res1 < res2 && val < res2)
        {
            val = res2;
            index1 = currPos;
            index2 = reqPos;
        }
    }

    swap(arr[index1], arr[index2]);

    REP(i,1,n)ans += abs(i - arr[i]);

    cout << ans;
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