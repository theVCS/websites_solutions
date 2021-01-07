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

    int t, n, x, y, st, di;

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> y;

        for (int start = 1; start <= x; start++)
        {
            for (int d = 1; d <= (y - x); d++)
            {
                if ((y - x) % d)
                {
                    continue;
                }

                if ((x - start) % d == 0 && (y - start) % d == 0 && (y - start) / d <= n - 1)
                {
                    for (int i = 0; i < n; i++)
                    {
                        cout << start << " ";
                        start += d;
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }

    return 0;
}