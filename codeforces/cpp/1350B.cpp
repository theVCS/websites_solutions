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

int maxLen(int index)
{
    if (index == n + 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int len = 1;
    int i = 2;

    while (index * i <= n)
    {
        if (arr[i * index] > arr[index])
            len = max(len, 1 + maxLen(index * i));

        i++;
    }

    return dp[index] = len;
}

void solve()
{
    cin >> n;

    dp[0] = -1;
    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        dp[i] = -1;
    }

    int ans = 0;

    REP(i,1,n+1)
    ans = max(ans,maxLen(i));

    cout<<ans<<endl;
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