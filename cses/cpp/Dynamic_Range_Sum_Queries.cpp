#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int blk = 700, m, n;
ll arr[maxN], f[287];

ll solve(int l, int r)
{
    l--, r--;
    ll sum = 0;
    int blk1 = l / blk;
    int blk2 = r / blk;

    if (blk1 == blk2)
    {
        for (int i = l; i <= r; i++)
        {
            sum += arr[i];
        }
    }
    else
    {
        for (int i = l; i < (blk1 + 1) * blk; i++)
        {
            sum += arr[i];
        }
        for (int i = blk1 + 1; i < blk2; i++)
        {
            sum += f[i];
        }
        for (int i = blk2 * blk; i <= r; i++)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;
    ll l, r;

    cin >> n >> m;

    REP(i, 0, n)
    {
        cin >> arr[i];
        f[i / blk] += arr[i];
    }

    while (m--)
    {
        cin >> c >> l >> r;

        if (c == 1)
        {
            l--;
            f[l / blk] -= arr[l];
            arr[l] = r;
            f[l / blk] += arr[l];
        }
        else
        {
            cout << solve(l, r) << endl;
        }
    }

    return 0;
}