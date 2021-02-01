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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, n, q, l, r;
    ll arr[100001];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        REP(i, 1, n + 1)
        {
            scanf("%lld", arr + i);
            arr[i] += arr[i - 1];
        }

        scanf("%d", &q);

        while (q--)
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", arr[r] - arr[l - 1]);
        }
    }

    return 0;
}