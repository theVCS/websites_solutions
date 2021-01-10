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

void knapSack(int fun[], int entrance[], int budget, int n)
{
    int t[n + 1][budget + 1];

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j < budget + 1; j++)
    {
        t[0][j] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < budget + 1; j++)
        {
            if (entrance[i - 1] <= j)
            {
                t[i][j] = max(fun[i - 1] + t[i - 1][j - entrance[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    ll i = 0;

    for (i = 0; i < budget + 1; i++)
    {
        if (t[n][i] == t[n][budget])
        {
            break;
        }
    }
    cout << i << " " << t[n][budget] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int budget, n;

        cin >> budget >> n;

        if (n == 0 && budget == 0)
        {
            return 0;
        }

        int entrance[n], fun[n];

        REP(i, 0, n)
        cin >> entrance[i], cin >> fun[i];

        knapSack(fun, entrance, budget, n);
    }

    return 0;
}