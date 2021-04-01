#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
bool dp[101][100001]; // [n][sum]

void solve()
{
    int n;

    cin >> n;

    dp[0][0] = true;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        dp[i][0] = true;
    }

    REP(i, 1, n + 1)
    {
        REP(j, 1, 100001)
        {
            if (j >= arr[i])
            {
                dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> res;

    REP(i, 1, 100001)
    {
        if(dp[n][i] == true)res.push_back(i);
    }

    cout << res.size() << endl;
    for(int e: res)cout << e << " ";
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