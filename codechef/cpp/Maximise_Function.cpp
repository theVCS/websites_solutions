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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        ll max1, max2, dum, res = 0;
        max1 = max2 = -1 * __LONG_LONG_MAX__;

        vector<ll> arr;

        while (n--)
        {
            cin >> dum;
            arr.push_back(dum);

            if (dum > max1)
            {
                max2 = max1;
                max1 = dum;
            }
            else if (dum <= max1 && dum >= max2)
            {
                max2 = dum;
            }
        }

        for (ll e : arr)
        {
            res = max(abs(max1 - e) + abs(e - max2) + abs(max1 - max2), res);
        }

        cout << res << endl;
    }

    return 0;
}