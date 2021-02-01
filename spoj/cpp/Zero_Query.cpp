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

int arr[50001], n, m;
int ml, mr, res;
const int Q = 5e4 + 10;

int dp(int i = ml, int sum1 = 0, int sum2 = 0)
{
    // without considering arr[i] == sum1
    // with considering arr[i] == sum2
    if (i > mr)
    {
        return 0;
    }
    else
    {
        // adding or not adding element in sequence
        int res1 = arr[i] + dp(i + 1, sum1 + );
        int res2 = dp(i + 1);

        if (res1 == 0)
        {
            res = max(res, res1);
        }
        if (res2 == 0)
        {
            res = max(res, res2);
        }
        
    }
}

struct query
{
    int l, r, index, lb;
} q[Q];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int blk = pow(n, 0.5);

    REP(i, 1, n + 1)
    cin >> arr[i];

    REP(i, 1, m + 1)
    {
        cin >> q[i].l >> q[i].r >> q[i].index;
        q[i].lb = q[i].l / blk;
    }

    return 0;
}