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

int knapSack(int W, int price[], int wt[], int n)
{
    //n->i && W->j
    int t[n + 1][W + 1];

    for (int i = 0; i < W + 1; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(t[i - 1][j - wt[i - 1]] + price[i - 1], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, n;

    cin >> s >> n;

    int wt[n], price[n];

    REP(i, 0, n)
    cin >> wt[i], cin >> price[i];

    cout << knapSack(s, price, wt, n);

    return 0;
}