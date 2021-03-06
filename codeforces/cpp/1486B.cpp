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

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> x, y;
        int dx, dy;

        bool isOdd = n & 1;

        while (n--)
        {
            cin >> dx >> dy;
            x.push_back(dx), y.push_back(dy);
        }
        sort(all(x));
        sort(all(y));

        if (isOdd)
        {
            cout << 1 << endl;
        }
        else
        {
            int mid1 = x.size() / 2;
            int mid2 = mid1 - 1;

            dx = x[mid1] - x[mid2] + 1;
            dy = y[mid1] - y[mid2] + 1;
            cout << 1LL * dx * dy << endl;
        }
    }

    return 0;
}