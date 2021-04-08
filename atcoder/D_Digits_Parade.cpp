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

string s;
int n;
int dp[maxN][13];

int ways(int index = 0, int rem = 0)
{
    if (index == n)
    {
        return (rem == 5);
    }

    if (dp[index][rem] != -1)
        return dp[index][rem];

    if (s[index] == '?')
    {
        int ans = 0;

        REP(i, 0, 10)
        ans = (ans + ways(index + 1, (rem * 10 + i) % 13)) % mod;

        return dp[index][rem] = ans;
    }
    else
    {
        return dp[index][rem] = ways(index + 1, (rem * 10 + (s[index] - '0')) % 13);
    }
}

void solve()
{
    cin >> s;
    n = s.size();

    REP(i,0,n+1)
    REP(j,0,13)
    dp[i][j]=-1;
    
    cout << ways();
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