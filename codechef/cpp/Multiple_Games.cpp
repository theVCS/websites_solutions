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

int arr[maxN], b[maxN], ans[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n, q, m, l, r, res = INT_MIN;

        cin >> n >> q >> m;

        REP(i, 0, n)
        cin >> arr[i];

        REP(i, 0, maxN)
        b[i] = 0, ans[i] = 0;

        map<pii, int> mp;

        while (q--)
        {
            cin >> l >> r;
            l--, r--;

            if (arr[l] > m)
                continue;
            else if (arr[l] <= m && arr[r] > m)
                b[arr[l]]++, b[m + 1]--;
            else if (arr[r] <= m)
            {
                b[arr[l]]++, b[m + 1]--;
                mp[{arr[l], arr[r]}]++;
            }
        }

        for (auto x : mp)
        {
            int k = x.first.first, p = x.first.second, l = x.second;

            b[p + k] -= 1, b[p + 2 * k] += 1;
            int c = p + 2 * k;

            while (c + p <= m)
            {
                c += p;
                b[c]--, b[c + k]++;
                c += k;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            b[i] += b[i - 1];
            res = max(b[i], res);
        }

        cout << res << endl;
    }

    return 0;
}