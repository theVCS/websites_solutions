#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100011
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll cnt[maxN][3];

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, q, l, r;
    ll k;

    scanf("%d %d", &n, &q);
    scanf("%lld", &k);

    REP(i, 1, n + 1)
    scanf("%lld", arr + i);

    REP(i, 1, n + 1)
    {
        cnt[i][0] = max(arr[i + 1] - 2, 0LL);
        cnt[i][1] = (arr[i + 1] - arr[i - 1] - 2) + cnt[i - 1][1];
        cnt[i][2] = k - arr[i];
    }

    // while (q--)
    // {
    //     scanf("%d %d", &l, &r);

    //     if (l == r)
    //         printf("%lld\n", k - 1);
    //     else if (l + 1 == r)
    //     {
    //         printf("%lld\n", cnt[l][0] + cnt[r][2]);
    //     }
    //     else
    //     {
    //         printf("%lld\n", cnt[l][0] + cnt[r][2] + (cnt[r - 1][1] - cnt[l - 2][1]));
    //     }
    // }

    return 0;
}