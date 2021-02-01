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

ll arr[101];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    int n, k;

    ll dum, res;

    while (t--)
    {
        res = 0;

        cin >> n >> k;

        REP(i, 1, n + 1)
        {
            cin >> dum;

            arr[i] = arr[i - 1] + dum;

            if (i > 1)
            {
                if ((dum * 1.0 / arr[i - 1]) * 100 > k * 1.0)
                {
                    ll d = ceil(dum * 100.0 / k);

                    d -= arr[i - 1];

                    res += d;

                    arr[i] += d;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}