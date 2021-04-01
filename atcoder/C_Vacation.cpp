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

struct happiness
{
    int a, b, c;
} arr[maxN];

int dp[maxN][2][2][2];

int happy(int n, int a_cnt = 0, int b_cnt = 0, int c_cnt = 0)
{
    if (n == 0)
    {
        return 0;
    }
    else if (dp[n][a_cnt][b_cnt][c_cnt] != -1)
    {
        return dp[n][a_cnt][b_cnt][c_cnt];
    }
    else
    {
        int hp = 0;

        if (a_cnt < 1)
            hp = max(hp, arr[n].a + happy(n - 1, 1, 0, 0));
        if (b_cnt < 1)
            hp = max(hp, arr[n].b + happy(n - 1, 0, 1, 0));
        if (c_cnt < 1)
            hp = max(hp, arr[n].c + happy(n - 1, 0, 0, 1));

        return dp[n][a_cnt][b_cnt][c_cnt] = hp;
    }
}

void solve()
{
    int n;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        dp[i][0][0][0] = -1;
        dp[i][0][1][0] = -1;
        dp[i][0][0][1] = -1;
        dp[i][0][1][1] = -1;
        dp[i][1][0][0] = -1;
        dp[i][1][1][0] = -1;
        dp[i][1][0][1] = -1;
        dp[i][1][1][1] = -1;
    }

    cout << happy(n);
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