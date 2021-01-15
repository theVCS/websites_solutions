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

ll coins[10001];

ll maxCoins(int n)
{
    ll t[n + 1];
    t[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (i != 1)
        {
            t[i] = max(coins[i - 1] + t[i - 2], t[i - 1]);
        }
        else
        {
            t[i] = max(coins[i - 1], t[i - 1]);
        }
    }
    return t[n];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    REP(k, 1, t + 1)
    {
        cin >> n;

        REP(i, 0, n)
        cin >> coins[i];

        cout << "Case " << k << ": " << maxCoins(n) << endl;
    }

    return 0;
}