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

struct juice
{
    ll price;
    int a, b, c;

    juice()
    {
        a = b = c = 0;
    }
} arr[1001];

ll dp[1001][2][2][2];

ll price(int n, int a = 0, int b = 0, int c = 0)
{
    if (a && b && c)
    {
        return 0;
    }
    else if (n == 0)
    {
        return INT_MAX;
    }
    else if (dp[n][a][b][c] != -1)
    {
        return dp[n][a][b][c];
    }
    else
    {
        return dp[n][a][b][c] = min(arr[n].price + price(n - 1, a || arr[n].a, b || arr[n].b, c || arr[n].c), price(n - 1, a, b, c));
    }
}

void solve()
{
    int n;
    string s;
    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i].price;
        cin >> s;

        for (char c : s)
        {
            if (c == 'A')
                arr[i].a = 1;
            else if (c == 'B')
                arr[i].b = 1;
            else
                arr[i].c = 1;
        }
    }

    memset(dp, -1, sizeof(dp));

    ll ans = price(n);

    cout << (ans == INT_MAX ? -1 : ans);
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