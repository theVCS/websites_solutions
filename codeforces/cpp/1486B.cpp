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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    ll xc, yc;

    cin >> t;

    while (t--)
    {
        int flagx = 1, flagy = 1;

        cin >> n;

        vector<ll> x, y;

        REP(i, 0, n)
        {
            cin >> xc >> yc;

            if (xc)
                flagx = 0;
            if (yc)
                flagy = 0;

            x.push_back(xc), y.push_back(yc);
        }

        if (flagx && flagy)
            flagx = flagy = 0;

        sort(all(x)), sort(all(y));

        if (n % 2)
        {
            cout << 1 + flagx + flagy << endl;
        }
        else
        {
            int mid = n / 2;
            int res = 1;

            if (x[mid - 1] != x[mid] || x[mid] != x[mid + 1])
                res *= 2;
            if (y[mid - 1] != y[mid] ||  x[mid] != x[mid + 1])
                res *= 2;

            cout << res + flagx + flagy << endl;
        }
    }

    return 0;
}