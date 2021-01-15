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

int maxSize(int n, int a, int b, int c)
{
    vector<int> vec;
    vec.push_back(a), vec.push_back(b), vec.push_back(c);

    int m = n;
    n = 3;

    int t[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        t[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (vec[i - 1] <= j)
            {
                t[i][j] = max(1 + t[i][j - vec[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][m];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, c;
    int x, y, z;

    cin >> n >> a >> b >> c;
    
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        x = y = z = -1;

        if (i >= a)
        {
            x = dp[i - a];
        }
        
        if (i >= b)
        {
            y = dp[i - b];
        }
        
        if (i >= c)
        {
            z = dp[i - c];
        }
        
        if (x == -1 && y == -1 && z == -1)
        {
            dp[i] = -1;
        }
        else
        {
            dp[i] = max(x, max(y, z)) + 1;
        }
    }
    
    cout << dp[n];

    return 0;
}