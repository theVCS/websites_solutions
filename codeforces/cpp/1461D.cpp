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
// #define endl "\n"
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

int n, q;
ll arr[maxN];
ll prefix[maxN];
map<ll, int> mp;

int bs(int start, int end, ll ele)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] <= ele && (mid == end || arr[mid + 1] > ele))
            return mid;
        else if (arr[mid] <= ele)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

void fun(int l, int r)
{
    if (l == r)
    {
        mp[arr[l]] = 1;
    }
    else if (l < r)
    {
        if (arr[l] == arr[r])
        {
            mp[prefix[r] - prefix[l - 1]] = 1;
            return;
        }

        mp[prefix[r] - prefix[l - 1]] = 1;
        ll mid = (arr[r] + arr[l]) / 2;
        mid = bs(l, r, mid);
        fun(l, mid);
        fun(mid + 1, r);
    }
}

void solve()
{
    mp.clear();

    cin >> n >> q;

    REP(i, 1, n)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + 1 + n);

    REP(i, 1, n)
    prefix[i] = prefix[i - 1] + arr[i];

    fun(1, n);

    ll m;

    REP(i, 1, q)
    {
        cin >> m;

        if (mp[m])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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