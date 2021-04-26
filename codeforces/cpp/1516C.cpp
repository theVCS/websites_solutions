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
#define maxN 111
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
int dp[101][200001];

int fun(int n, int sum)
{
    if (sum == 0)
        return 1;
    else if (n == 0)
        return 0;
    else if (dp[n][sum] != -1)
        return dp[n][sum];
    else if (sum >= arr[n])
        return dp[n][sum] = (fun(n - 1, sum - arr[n]) || fun(n - 1, sum));
    else
        return dp[n][sum] = fun(n - 1, sum);
}

void solve()
{
    int n, sum = 0;

    cin >> n;

    REP(i, 1, n)
    cin >> arr[i], sum += arr[i];

    memset(dp, -1, sizeof(dp));

    if (sum % 2)
    {
        cout << 0;
        return;
    }

    if (fun(n, sum / 2))
    {
        while (true)
        {
            REP(i, 1, n)
            {
                if (arr[i] % 2 == 0)
                    arr[i] /= 2;
                else
                {
                    cout << 1 << endl
                         << i;
                    return;
                }
            }
        }
    }
    else
    {
        cout << 0;
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}