#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// using top-down approach

ll t[maxN][maxN];

ll nck_td(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    else if (n == k || k == 0)
    {
        return 1;
    }
    else if (t[n][k] != -1)
    {
        return t[n][k];
    }
    else
    {
        return t[n][k] = nck_td(n - 1, k - 1) + nck_td(n - 1, k);
    }
}

ll nck_bu(int n, int k)
{
    if (n < k)
    {
        return 0;
    }

    ll t[n + 1][k + 1];

    for (int i = 0; i < min(n + 1, k + 1); i++)
    {
        t[i][i] = 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < min(i, k + 1); j++)
        {
            if (i > j)
            {
                t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
            }
        }
    }
    return t[n][k];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // memset(t, -1, maxN * maxN);

    int n, k;

    cin >> n >> k;

    cout << nck_bu(n, k);

    return 0;
}