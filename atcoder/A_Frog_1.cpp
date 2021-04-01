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
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
int arr[maxN];
int dp[maxN];

int cost(int index)
{
    if (index >= n)
    {
        return 0;
    }
    else if (dp[index] != -1)
    {
        return dp[index];
    }
    else if(index == n - 1)
    {
        return dp[index] = abs(arr[index] - arr[index + 1]);
    }
    else
    {
        return dp[index] = min(abs(arr[index] - arr[index + 1]) + cost(index + 1), abs(arr[index] - arr[index + 2]) + cost(index + 2));
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        dp[i] = -1;    
    }

    cout << cost(1);
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