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

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        REP(i, 0, n)
        cin >> arr[i];

        int parent = 0, child, lev = 0, i = 1;
        int level[n + 1], res = 0;

        level[1] = lev;

        while (i < n)
        {
            lev++;
            while ((i < n && arr[i] > arr[i - 1]) || parent == 0)
            {
                res = max(res, lev);
                level[arr[i]] = lev;
                parent++;
                i++;
            }

            lev++;

            while (i < n && parent)
            {
                parent--;
                level[arr[i]] = lev;
                res = max(res, lev);
                i++;

                while (i < n && arr[i] > arr[i - 1])
                {
                    level[arr[i]] = lev;
                    i++;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}