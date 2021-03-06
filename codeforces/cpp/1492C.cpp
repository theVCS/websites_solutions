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
#define maxN 200001
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

string s, t;
int n, m;
vector<int> arr[26];
int mxIndex[maxN];
int minIndex[maxN];

int bs(vector<int> &arr, int ele)
{
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] < ele && (mid == n - 1 || arr[mid + 1] >= ele))
        {
            return mid;
        }
        else if (arr[mid] >= ele)
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

int bs1(vector<int> &arr, int ele)
{
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] > ele && (mid == 0 || arr[mid - 1] <= ele))
        {
            return mid;
        }
        else if (arr[mid] <= ele)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

void solve()
{
    cin >> n >> m;
    cin >> s >> t;

    REP(i, 0, n - 1)
    {
        arr[s[i] - 'a'].push_back(i);
    }

    int res = 0;
    int mx = INF;

    RREP(i, m - 1, 0)
    {
        int currEle = t[i] - 'a';
        int index = bs(arr[currEle], mx);
        mx = arr[currEle][index];
        mxIndex[i] = mx;
    }

    int mn = -1;
    REP(i, 0, m - 1)
    {
        int currEle = t[i] - 'a';
        int index = bs1(arr[currEle], mn);
        mn = arr[currEle][index];
        minIndex[i] = mn;

        if (i)
            res = max(res, mxIndex[i] - minIndex[i - 1]);
    }

    cout << res;
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