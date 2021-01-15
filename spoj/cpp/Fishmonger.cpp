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

int tim[51][51];
int tolls[51][51];

int knaSack(int t, int n, int curr = 1)
{
    if (curr == n || t == 0)
    {
        return 0;
    }
    else
    {
        int res = INT_MAX;
        for (int i = curr + 1; i < n + 1; i++)
        {
            if (tim[curr][i] <= t)
            {
                res = min(knaSack(t - tim[curr][i], n, i), res);
            }
        }
        return res;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;

    while (true)
    {
        cin >> n >> t;

        if (n == 0 && t == 0)
        {
            return 0;
        }

        REP(i, 1, n + 1)
        REP(j, 1, n + 1)
        cin >> tim[i][j];

        REP(i, 1, n + 1)
        REP(j, 1, n + 1)
        cin >> tolls[i][j];
    }

    cout << knaSack(t, n) << endl;

    return 0;
}