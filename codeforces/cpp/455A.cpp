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
#define maxN 100001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll dp[maxN];

ll fun(int n)
{
    if (n == 1)
    {
        return arr[n];
    }
    else if (n == 0)
    {
        return 0;
    }
    else if (dp[n] != -1)
    {
        return dp[n];   
    }
    else
    {
        return dp[n] = max(fun(n - 1), arr[n] * n + fun(n - 2));
    }
}

void solve()
{
    int n, dum, ele = -1;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> dum;
        arr[dum]++;
        ele = max(ele,dum);
    }

    memset(dp,-1,sizeof(dp));

    cout << fun(ele);
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