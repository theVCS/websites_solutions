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

const int blk = 700, N = 2e5 + 1;
ll f[287], arr[N];
int n;

void init()
{
    REP(i, 0, 287)f[i] = __LONG_LONG_MAX__;

    for (int i = 0; i < n; i++)
    {
        f[i / blk] = min(f[i / blk], arr[i]);
    }
}

ll solve(int l, int r)
{
    l--, r--;
    int blk1 = l / blk;
    int blk2 = r / blk;

    ll res = __LONG_LONG_MAX__;

    if (blk1 == blk2)
    {
        for (int i = l; i <= r; i++)
        {
            res = min(res, arr[i]);
        }
    }
    else
    {
        for (int i = l; i < (blk1 + 1) * blk; i++)
        {
            res = min(res, arr[i]);
        }
        for (int i = blk1 + 1; i < blk2; i++)
        {
            res = min(res, f[i]);
        }
        for (int i = blk2 * blk; i <= r; i++)
        {
            res = min(res, arr[i]);
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, l, r;

    cin >> n >> q;

    REP(i, 0, n)
    cin >> arr[i];

    init();

    while (q--)
    {
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }

    return 0;
}