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
#define maxN 101
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

int arr[maxN];
int brr[maxN];

void solve()
{
    int n;

    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        brr[i] = arr[i];
    }

    sort(brr + 1, brr + 1 + n);

    if(arr[1] == brr[n] && arr[n] == brr[1])
    {
        cout<<3<<endl;
        return;
    }

    bool flag = false;

    REP(i, 2, n - 1)
    {
        if (arr[i] != brr[i])
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        // some elements in [2,n-1] is sorted
        if (arr[1] == brr[1] || arr[n] == brr[n])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    else
    {
        // all elements in arr is sorted
        if (arr[1] == brr[1] && arr[n] == brr[n])
        {
            cout << 0 << endl;
        }
        else if (arr[1] == brr[1] || arr[n] == brr[n])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
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