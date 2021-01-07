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

    int t, n, dum, x;

    cin >> t;

    while (t--)
    {
        int l = -1, r;
        ll sum = 0;
        cin >> n >> x;

        for (int i = 1; i <= n; i++)
        {
            cin >> dum;

            sum += dum;

            if (dum % x)
            {
                if (l == -1)
                {
                    l = i;
                }
                r = i;
            }
        }

        if (l == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            if (sum % x)
            {
                cout << n << endl;
            }
            else
            {
                cout << max(n - l, r - 1) << endl;
            }
        }
    }

    return 0;
}