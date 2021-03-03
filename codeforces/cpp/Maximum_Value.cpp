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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        REP(i, 0, n)
        cin >> arr[i];

        sort(arr, arr + n);

        ll res = -1 * __LONG_LONG_MAX__;

        REP(i, 0, n - 1)
        {
            res = max({res, arr[0] * arr[i + 1] - arr[0] + arr[i + 1]});
            res = max({res, arr[n - 1] * arr[i] + arr[n - 1] - arr[i]});
        }

        cout << res << endl;
    }

    return 0;
}