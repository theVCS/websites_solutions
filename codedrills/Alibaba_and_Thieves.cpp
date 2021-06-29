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

struct guard
{
    ll start, end;
} arr[maxN];
int n;

int bs(ll timer)
{
    int start = 1, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].end < timer && (mid == n || arr[mid + 1].end >= timer))
        {
            return mid;
        }
        else if (arr[mid].end >= timer)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int dp[maxN];

int fun(int index)
{
    if (index == -1 || index == 0)
    {
        return 0;
    }
    else if (dp[index] != -1)
    {
        return dp[index];
    }
    else
    {
        return dp[index] = max(1 + fun(bs(arr[index].end)), fun(index + 1));
    }
}

bool cmp(guard a, guard b)
{
    if (a.end == b.end)
        return a.start > b.start;
    return a.end > b.end;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i].start >> arr[i].end;
        dp[i] = -1;
    }
    dp[0] = -1;

    sort(arr + 1, arr + 1 + n, cmp);

    cout << fun(n) << endl;
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