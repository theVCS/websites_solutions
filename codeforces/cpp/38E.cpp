#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 3001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct marble
{
    ll index, price;
} arr[maxN];

bool cmp(marble a, marble b)
{
    return (a.index < b.index);
}

int n;
ll dp[maxN][maxN];

ll cost(int index, int prevIndex)
{
    if (index >= n + 1)
    {
        return 0;
    }
    else if (dp[index][prevIndex] != -1)
    {
        return dp[index][prevIndex];
    }
    else
    {
        // we may pin index-th marble or may not pin
        return dp[index][prevIndex] = min(arr[index].index - arr[prevIndex].index + cost(index + 1, prevIndex), arr[index].price + cost(index + 1, index));
    }
}

void solve()
{
    cin >> n;


    REP(i, 1, n + 1)
    {
        cin >> arr[i].index >> arr[i].price;
    }

    memset(dp, -1, sizeof(dp));

    sort(arr + 1, arr + 1 + n, cmp);

    // always required to pin left most
    ll ans = arr[1].price + cost(2, 1);
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