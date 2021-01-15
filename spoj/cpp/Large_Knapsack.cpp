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

int knapsack(int val[], int wt[], int n, int W)
{
    int t[2][W + 1];

    for (int i = 0; i < W + 1; i++)
    {
        t[0][i] = 0;
        t[1][i] = 0;
    }

    int i = 1, j;

    while (i <= n)
    {
        j = 1;

        if (i % 2)
        {
            while (j <= W)
            {
                if (wt[i - 1] <= j)
                {
                    t[1][j] = max(val[i - 1] + t[0][j - wt[i - 1]], t[0][j]);
                }
                else
                {
                    t[1][j] = t[0][j];
                }
                j++;
            }
        }
        else
        {
            while (j <= W)
            {
                if (wt[i - 1] <= j)
                {
                    t[0][j] = max(val[i - 1] + t[1][j - wt[i - 1]], t[1][j]);
                }
                else
                {
                    t[0][j] = t[1][j];
                }
                j++;
            }
        }
        i++;
    }
    if (n % 2)
    {
        return t[1][W];
    }
    else
    {
        return t[0][W];
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W, n;

    cin >> W >> n;

    int val[n], wt[n];

    REP(i, 0, n)
    cin >> val[i] >> wt[i];

    cout << knapsack(val, wt, n, W);

    return 0;
}