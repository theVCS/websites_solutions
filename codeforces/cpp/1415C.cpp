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

ll n, p, k;
string s;
ll x, y;
ll dp[maxN];

// we could remove 1 cell or make a platform on a given cell
ll fun(int index = 1)
{
    if (index > n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    if (s[index - 1] == '1')
    {
        return dp[index] = min(fun(index + k), y + fun(index + 1));
    }
    else
    {
        return dp[index] = min(x + fun(index + k), y + fun(index + 1));
    }
}

int platforms[maxN];

void solve()
{
    cin >> n >> p >> k;
    cin >> s;
    cin >> x >> y;

    REP(i,1,n+1)
    {
        
    }

    // memset(dp, -1, sizeof(dp));
    // cout << fun(p) << endl;
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