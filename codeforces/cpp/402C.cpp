#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
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

    int t, n, p, k;

    cin >> t;

    while (t--)
    {
        cin >> n >> p;

        k = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                k++;

                if (k > (2 * n + p))
                {
                    i = n + 1;
                    j = n + 1;
                    break;
                }

                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}