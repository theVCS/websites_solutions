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
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int tb[11][1001];

int dp(int arr[], int n, int s)
{
    if (n == 0 || s == 0)
        return 0;
    else if (tb[n][s] != -1)
        return tb[n][s];
    else if (s >= arr[n - 1])
        return tb[n][s] = max(1 + dp(arr, n - 1, s - arr[n - 1]), dp(arr, n - 1, s));
    else
        return tb[n][s] = dp(arr, n - 1, s);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        int arr[n];

        REP(i, 0, n)
        cin >> arr[i];

        memset(tb, -1, sizeof(tb));

        cout << dp(arr, n, s) << endl;
    }

    return 0;
}