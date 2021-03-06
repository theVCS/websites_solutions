#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define endl "\n"
#define INF 2000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];

bool isValid(int c, int n, int dist)
{
    int cnt = 0, prev = -1 * INF;

    REP(i, 1, n + 1)
    {
        if (arr[i] - prev >= dist)
            cnt++, prev = arr[i];
        if (cnt >= c)
            return true;
    }

    return false;
}

void solve()
{
    int n, c;
    int ans = 0;

    cin >> n >> c;

    REP(i, 1, n + 1)
    cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    int start = 0, end = arr[n] - arr[1];

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isValid(c, n, mid))
            ans = max(ans, mid), start = mid + 1;
        else
            end = mid - 1;
    }

    cout << ans << endl;
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