#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 150001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int res, k;

void dp(int index, int sum = INT_MAX)
{
    if (index < k)
        return;
    if (sum > arr[index] - arr[index - k])
    {
        res = index - k + 1;
        sum = arr[index] - arr[index - k];
    }

    dp(index - 1, sum);
}

void solve()
{
    int n;

    cin >> n >> k;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    // int res = arr[k];
    // int index = 1;

    // REP(i, 1, n - k + 2)
    // {
    //     int r = i + k - 1;
    //     int l = i - 1;

    //     if (res > (arr[r] - arr[l]))
    //     {
    //         res = (arr[r] - arr[l]);
    //         index = i;
    //     }
    // }
    dp(n);

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