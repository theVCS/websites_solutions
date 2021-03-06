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

int n;
int arr[1001];
int res[1001][1001];

// 1 -> true
// 2 -> false

bool query(int i, int r)
{
    if (res[arr[i]][arr[r]])
    {
        if (res[arr[i]][arr[r]] == 1)
            return true;
        else
            return false;
    }

    cout << 1 << " " << arr[i] << " " << arr[r] << endl;
    fflush(stdout);

    string s;
    cin >> s;

    if (s[0] == 'Y')
    {
        res[arr[i]][arr[r]] = 2;
        return false;
    }
    else
    {
        res[arr[i]][arr[r]] = 1;
        return true;
    }
}

int pivot(int l, int r)
{
    int i = l;

    REP(j, l, r - 1)
    {
        if (query(j, r) == false)
        {
            swap(arr[j], arr[i++]);
        }
    }

    swap(arr[i], arr[r]);
    return i;
}

int quickSort(int l, int r)
{
    if (l < r)
    {
        int index = pivot(l, r);
        quickSort(l, index - 1);
        quickSort(index + 1, r);
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    arr[i] = i;

    quickSort(1, n);

    int i = 2;
    while (i <= n)
    {
        if (query(i - 1, i))
        {
            cout << 0 << " ";
            REP(j, 1, n)
            cout << 0 << " ";
            cout << endl;
            return;
        }
        i++;
    }

    cout << 0 << " ";
    REP(i, 1, n)
    cout << arr[i] << " ";
    cout << endl;
    return;
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