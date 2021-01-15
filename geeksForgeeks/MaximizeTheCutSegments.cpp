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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n + 1];

    dp[0] = 0;

    int a, b, c;

    for (int i = 1; i < n + 1; i++)
    {
        a = b = c = -1;

        if (i >= x)
        {
            a = dp[i - x];
        }

        if (i >= y)
        {
            b = dp[i - y];
        }

        if (i >= z)
        {
            c = dp[i - z];
        }

        if (a == -1 && b == -1 && c == -1)
        {
            dp[i] = -1;
        }
        else
        {
            dp[i] = max(a, max(b, c)) + 1;
        }
    }
    return max(dp[n], 0);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y, z;

    while (true)
    {
        cin >> n >> x >> y >> z;
        cout << maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
}