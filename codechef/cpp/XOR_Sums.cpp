#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 998244353
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll ans[maxN];

void solve(ll res, int n, int i, int len)
{
    if (i > n)
    {
        return;
    }
    else
    {
        ans[len] = (ans[len] + res) % mod;

        solve(res ^ arr[i], n, i + 1, len + 1);
        solve(res, n, i + 1, len);
    }
}

int main(int argc, char const *argv[])
{
    int n, q, x;

    cin >> n;

    REP(i, 0, n)
    {
        scanf("%lld", arr + i);
    }

    cin >> q;

    solve(0, n, 0, 0);

    while (q--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }

    return 0;
}