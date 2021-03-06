#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, blk, arr[maxN], f[310];

void init()
{
    int res = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        res = min(res, arr[i]);

        if ((i + 1) % blk == 0)
        {
            f[i / blk] = res;
            res = INT_MAX;
        }
    }

    f[n / blk] = res;
}

int srDec(int l, int r)
{
    int ib = l / blk;
    int lb = r / blk;
    int res = INT_MAX;

    if (ib == lb)
    {
        for (int i = l; i <= r; i++)
        {
            res = min(res, arr[i]);
        }
    }
    else
    {
        for (int i = l; i < (ib + 1) * blk; i++)
        {
            res = min(res, arr[i]);
        }

        for (int i = ib + 1; i < lb; i++)
        {
            res = min(res, f[i]);
        }

        for (int i = lb * blk; i <= r; i++)
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

    cin >> n;

    blk = sqrt(n);

    REP(i, 0, n)
    cin >> arr[i];

    init();

    cin >> q;

    while (q--)
    {
        cin >> l >> r;
        cout << srDec(l, r) << endl;
    }

    return 0;
}