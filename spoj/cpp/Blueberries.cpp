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

int berries[1001];

int mb(int n, int k)
{
    int t[n + 1][k + 1];

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }

    for (int i = 0; i < k + 1; i++)
    {
        t[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (berries[i - 1] <= j)
            {
                if (i != 1)
                {
                    t[i][j] = max(berries[i - 1] + t[i - 2][j - berries[i - 1]], t[i - 1][j]);
                }
                else
                {
                    t[i][j] = max(berries[i - 1], t[i - 1][j]);
                }
            }
            else
            {
                t[i][j] = t[i - 1][j];
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

    int t, n, k;

    cin >> t;

    REP(i, 1, t + 1)
    {
        cin >> n >> k;

        REP(j, 0, n)
        cin >> berries[j];

        cout << "Scenario #" << i << ": " << mb(n, k) << endl;
    }

    return 0;
}