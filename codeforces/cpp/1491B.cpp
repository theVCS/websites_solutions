#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
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

    int t, n;
    ll u, v;

    cin >> t;

    while (t--)
    {
        cin >> n >> u >> v;

        bool flag = true, diffG = false;

        REP(i, 0, n)
        {
            cin >> arr[i];

            if (i && arr[i] != arr[i - 1])
            {
                flag = false;

                if (abs(arr[i] - arr[i - 1]) > 1)
                    diffG = true;
            }
        }

        if (flag)
        {
            cout << v + min(v, u) << endl;
        }
        else if (diffG)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << min(v, u) << endl;
        }
    }

    return 0;
}