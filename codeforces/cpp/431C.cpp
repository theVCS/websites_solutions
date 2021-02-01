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

ll ans[101][2];
int n, k, d;

ll paths(int sum, int col)
{
    if (sum > n)
    {
        return 0;
    }
    else if (sum == n)
    {
        if (col)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (ans[sum][col] != -1)
    {
        return ans[sum][col];
    }

    ll res = 0;

    for (int i = 1; i <= k; i++)
    {
        if (i >= d)
        {
            res = (res + paths(sum + i, 1)) % mod;
        }
        else
        {
            res = (res + paths(sum + i, col)) % mod;
        }
    }
    return ans[sum][col] = res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ans, -1, sizeof(ans));

    cin >> n >> k >> d;

    cout << paths(0, 0) << endl;

    return 0;
}