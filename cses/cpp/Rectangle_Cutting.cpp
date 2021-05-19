#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int res[501][501];

int dp(int a, int b)
{
    if (a == b || a <= 0 || b <= 0)
    {
        return 0;
    }
    else if (res[a][b] != -1)
    {
        return res[a][b];
    }
    else
    {
        int ans = INT_MAX;

        REP(i, 1, b / 2 + 1)
        ans = min({ans, 1 + dp(a, b - i) +  dp(a, i)});
        REP(i, 1, a / 2 + 1)
        ans = min({ans, 1 + dp(i, b) + dp(a - i, b)});

        return res[a][b] = ans;
    }
}

void solve()
{
    int a, b;

    cin >> a >> b;
    memset(res, -1, sizeof(res));
    cout << dp(a, b);
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